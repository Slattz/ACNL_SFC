#ifndef BOSS_H
#define BOSS_H

#include "Headers/values.h"
#include <QByteArray>

#define BOSS_MAGICSTR "boss"
#define BOSS_MAGICNUM 0x00010001

#pragma pack(push, 1)

typedef struct {
    //BOSS Header
    char MagicStr[4]; //"boss"
    u32 MagicNum; //0x00010001
    u32 FileSize; //Can't be < 0x15A
    u64 ReleaseDate;
    u16 Unk0; //Always 0x0001
    u16 Padding;
    u16 Cnthdr_HashType; //Always 0x0002
    u16 Cnthdr_RSASize; //Always 0x0002
    u8  Ctr[12]; // First 12 byte of ctr

    //Content Header; Start of encryption
    u8 Unk1[0x10]; //Usually 0x80 followed by 0x00
    u16 ExtdataInfo; //For generating extdata filepath
    u8 HeaderHash[0x20];
    u8 HeaderSig[0x100];

    //Payload Content Header
    u64 ProgramID;
    u32 Unk2; //Typically zero
    u32 DataType;
    u32 PayloadSize;
    u32 NsDataId;
    u32 Unk3;
    u8 PayloadHash[0x20];
    u8 PayloadSig[0x100];
} BossHeader;

#pragma pack(pop)

class BOSS
{
public:
    BOSS(void);
    ~BOSS(void);
    void SetTitleIDLower(u32 TIDLower);
    void UpdateFileSize(void);
    bool AddPayload(u8* buffer, int size, u32 ContentDataType);
    bool DeletePayload(void);
    void DumpAsFile(const QString path);
    void Crypt(void);

protected:
    void GenCTR(void);
    void UpdatePayloadHash(void);
    void SetupBossHeader(void);

    BossHeader *m_BossHeader;
    bool m_Encrypted = false;
    QByteArray *m_AESKey = nullptr;
    QByteArray *m_AESCtr = nullptr;
    bool m_HasPayload = false;
    QByteArray *m_Payload = nullptr;
};

#endif // BOSS_H
