#include <QtDebug>
#include <QtCore>
#include "Headers/utils.hpp"
#include "Headers/file.h"

#define KEYOFFSET 0xDBD0
static const QString kHash = "a65cdf7e465719081f4107df5ad53787dfc8e569b7d79eefd703676b26ba04639f4fd542057a3e129c3dd9e7624433f66cab23d7fa7ee4f2641d4736e3c7e2f5";
static QByteArray* g_Key = nullptr;

static void SetEmptyKey(void) {
    QByteArray *nokey = new QByteArray;
    g_Key = nokey;
}

KeyResult Utils::SetupKey(void) {
    QString localpath = QCoreApplication::applicationDirPath() + "/boot9.bin";
    QStringList datapaths = QStandardPaths::standardLocations(QStandardPaths::AppDataLocation);

    QString datapath = datapaths.at(0);
    datapath.replace("/" + QCoreApplication::applicationName(), "");

#ifdef Q_OS_WIN32
    datapath += "/3ds/boot9.bin";
#else
    datapath += "/.3ds/boot9.bin";
#endif

    File *boot9 = new File(localpath, QFile::ReadOnly, false);
    if (!boot9->Exists()) {
        boot9 = new File(datapath, QFile::ReadOnly, false);
    }

    if (boot9->Exists() && boot9->m_file->isOpen()) {
        QByteArray* key = boot9->Read(KEYOFFSET, 16);
        if (key->isEmpty() || key->size() != 16) {
            boot9->Close();
            SetEmptyKey();
            return KeyResult::ByteArrayBadSize;
        }

        return Utils::SetKey(key);
    }

    else {
        SetEmptyKey();
        return KeyResult::FileNoExist;
    }
}

KeyResult Utils::SetKey(QByteArray* key) {
    if (key->isEmpty() || key->size() != 16)
        return KeyResult::ByteArrayBadSize;

    QCryptographicHash *sha = new QCryptographicHash(QCryptographicHash::Sha512);
    sha->addData(*key);
    if (sha->result().toHex() == kHash) {
        g_Key = key;
        return KeyResult::NoError;
    }

    else SetEmptyKey();

    return KeyResult::HashMismatch;
}


QByteArray* Utils::GetKey(void) {
    if (g_Key == nullptr) {
        SetEmptyKey();
    }

    return g_Key;
}


bool Utils::SetupOutDir(const QString &outdir) {
    if (!QDir(outdir).exists()) {
        if(!QDir().mkpath(outdir))
            return false;
    }

    return true;
}
