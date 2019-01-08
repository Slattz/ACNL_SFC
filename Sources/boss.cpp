#include <QtDebug>
#include <cstring>
#include <QtEndian>
#include <QDateTime>
#include <QRandomGenerator>
#include <QCryptographicHash>
#include "Headers/boss.h"
#include "Sources/aes.hpp"
#include "Headers/file.h"
#include "Headers/utils.hpp"

static const u16 g_u16zero = 0x0000;
static const u32 g_CTREnd = qToBigEndian(0x00000001);

BOSS::~BOSS(void)
{
    delete m_BossHeader;
    delete m_AESCtr;
    if (m_Payload) {
        m_Payload->clear();
        delete m_Payload;
    }
}


BOSS::BOSS(void)
{
    m_BossHeader = new BossHeader;
    m_AESCtr = new QByteArray;
    m_AESKey = new QByteArray;
    this->SetupBossHeader();

    m_AESKey = Utils::GetKey();
    m_AESCtr->append(reinterpret_cast<char*>(&m_BossHeader->Ctr), 12);
    m_AESCtr->append(reinterpret_cast<const char*>(&g_CTREnd), 0x4);
    m_Encrypted = false;
}

void BOSS::GenCTR(void) {
    QRandomGenerator *gen = QRandomGenerator::global();
    u64 Ctr = gen->generate64();
    u32 Ctr2 = gen->generate();
    qDebug() << "CTR: " << QString::number(qToBigEndian(Ctr), 16) + QString::number(qToBigEndian(Ctr2), 16);
    memcpy(m_BossHeader->Ctr, &Ctr, 8);
    memcpy(m_BossHeader->Ctr+8, &Ctr2, 4);
}

void BOSS::UpdatePayloadHash(void) {
    QCryptographicHash *sha256 = new QCryptographicHash(QCryptographicHash::Sha256);
    sha256->addData(reinterpret_cast<char*>(&m_BossHeader->ProgramID), 0x1C);
    sha256->addData(reinterpret_cast<const char*>(&g_u16zero), 0x2);
    if (m_HasPayload) sha256->addData(m_Payload->data(), m_Payload->size());
    memcpy(m_BossHeader->PayloadHash, sha256->result(), 0x20);
    qDebug() << "Payload Hash: " << sha256->result().toHex();
}

void BOSS::SetTitleIDLower(u32 TIDLower) {
    bool wasEnc = false;
    if (m_Encrypted) {
        wasEnc = true;
        this->Crypt(); //Decrypt
    }
    m_BossHeader->ProgramID = qToBigEndian(static_cast<u64>(0x0004000000000000|TIDLower));
    if (wasEnc) this->Crypt(); //Re-Encrypt
}

void BOSS::UpdateFileSize(void) {
    u32 filesize = sizeof(BossHeader);
    if (m_HasPayload) filesize += static_cast<u32>(m_Payload->size());

    m_BossHeader->FileSize = qToBigEndian(static_cast<u32>(filesize));
}

void BOSS::SetupBossHeader(void) {
    qstrncpy(m_BossHeader->MagicStr, BOSS_MAGICSTR, 5);
    m_BossHeader->MagicNum = qToBigEndian(static_cast<u32>(BOSS_MAGICNUM));
    m_BossHeader->FileSize = qToBigEndian(static_cast<u32>(0xDEADB055));
    m_BossHeader->ReleaseDate = qToBigEndian(static_cast<u64>(QDateTime::currentSecsSinceEpoch()));
    m_BossHeader->Unk0 = qToBigEndian(static_cast<u16>(0x0001));
    m_BossHeader->Padding = 0;
    m_BossHeader->Cnthdr_HashType = qToBigEndian(static_cast<u16>(0x0002));
    m_BossHeader->Cnthdr_RSASize = qToBigEndian(static_cast<u16>(0x0002));
    this->GenCTR();

    //Content Header; Encryption starts here
    memset(&m_BossHeader->Unk1, 0, 0x10);
    m_BossHeader->ExtdataInfo = qToBigEndian(static_cast<u16>(0x0001));
    memset(m_BossHeader->HeaderSig, 0xFF, 0x100);

    QCryptographicHash *sha256 = new QCryptographicHash(QCryptographicHash::Sha256);
    sha256->addData(reinterpret_cast<char*>(&m_BossHeader->Unk1), 0x12);
    sha256->addData(reinterpret_cast<const char*>(&g_u16zero), 0x2);
    memcpy(m_BossHeader->HeaderHash, sha256->result(), 0x20);

    //Payload Content Header
    m_BossHeader->ProgramID = qToBigEndian(static_cast<u64>(0x0004000000000000));
    m_BossHeader->Unk2 = 0;
    m_BossHeader->DataType = qToBigEndian(static_cast<u32>(0x00010000)); //Payload specific ID needs to be OR'd to this value
    m_BossHeader->PayloadSize = 0; //No payload at time of creation, therefore size is 0
    m_BossHeader->NsDataId = qToBigEndian(static_cast<u32>(0x00000004));
    m_BossHeader->Unk3 = qToBigEndian(static_cast<u32>(0x00000001));
    this->UpdatePayloadHash();
    memset(m_BossHeader->PayloadSig, 0xFF, 0x100);
    this->UpdateFileSize();
    m_HasPayload = false;
    m_Encrypted = false;

}

bool BOSS::AddPayload(u8* buffer, int size, u32 ContentDataType) {
    if (buffer == nullptr || size <= 0 || m_HasPayload) {
        return false;
    }

    bool wasEnc = false;
    if (m_Encrypted) {
        wasEnc = true;
        this->Crypt(); //Decrypt
    }

    m_Payload = new QByteArray(reinterpret_cast<char*>(buffer), size);
    if(!m_Payload->isEmpty()) {
        m_HasPayload = true;
        m_BossHeader->PayloadSize = qToBigEndian(static_cast<u32>(m_Payload->size()));
        m_BossHeader->DataType = qToBigEndian(static_cast<u32>(ContentDataType));
        this->UpdatePayloadHash();
        this->UpdateFileSize();
        if (wasEnc) this->Crypt(); //Re-Encrypt
        return true;
    }

    else {
        delete m_Payload;
        m_Payload = nullptr;
        m_HasPayload = false;
    }

    if (wasEnc) this->Crypt(); //Re-Encrypt
    return false;
}

bool BOSS::DeletePayload(void) {
    bool wasEnc = false;
    if (!m_HasPayload) return false;

    if (m_Encrypted) {
        wasEnc = true;
        this->Crypt(); //Decrypt
    }

    if (m_Payload) {
        m_Payload->clear();
        delete m_Payload;
    }
    m_Payload = nullptr;
    m_HasPayload = false;
    m_BossHeader->PayloadSize = 0;
    m_BossHeader->DataType = qToBigEndian(static_cast<u32>(0x00010000));
    this->UpdatePayloadHash();
    this->UpdateFileSize();
    if (wasEnc) this->Crypt(); //Re-Encrypt
    return true;
}

void BOSS::DumpAsFile(const QString path) {
    File *boss = new File(path, QFile::ReadWrite|QFile::Append|QFile::Truncate);
    QByteArray bytes(reinterpret_cast<char*>(m_BossHeader), sizeof(BossHeader));
    boss->Append(bytes);
    if (m_HasPayload) {
        boss->Append(*m_Payload);
    }

    boss->Close();
    delete boss;
}

/* Symmetrical operation: same function for encrypting as for decrypting */
void BOSS::Crypt(void) {
    AES_ctx ctx;
    if (m_AESKey->isEmpty()) {
        QMessageBox::warning(nullptr, "Failed Crypting BOSS", "m_AESKey is empty! Did you provide a bootrom dump?");
        return;
    }

    if (m_AESCtr->isEmpty()) {
        QMessageBox::warning(nullptr, "Failed Crypting BOSS", "m_AESCtr is empty! Report this to the dev.");
        return;
    }

    QByteArray bytes(reinterpret_cast<char*>(m_BossHeader)+0x28, sizeof(BossHeader)-0x28);
    if (m_HasPayload) bytes.append(*m_Payload);

    AES_init_ctx_iv(&ctx, reinterpret_cast<u8*>(m_AESKey->data()), reinterpret_cast<u8*>(m_AESCtr->data()));
    AES_CTR_xcrypt_buffer(&ctx, reinterpret_cast<u8*>(bytes.data()), static_cast<u32>(bytes.size()));

    /* Write crypted data back to buffer */
    memcpy(reinterpret_cast<char*>(m_BossHeader)+0x28, bytes.data(), sizeof(BossHeader)-0x28);
    memcpy(m_Payload->data(), bytes.data()+622, static_cast<u32>(m_Payload->size()));
    m_Encrypted = !m_Encrypted; //Flip our encrypted bool to keep track of state
    return;
}
