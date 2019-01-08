#ifndef UTILS_HPP
#define UTILS_HPP

#include <QByteArray>
#include <QCryptographicHash>
#include <QString>

enum class KeyResult : quint8 {
    NoError = 0,
    FileNoExist = 1,
    ByteArrayBadSize = 2,
    HashMismatch = 3
};

namespace Utils
{
    KeyResult SetupKey(void);
    KeyResult SetKey(QByteArray* key);
    QByteArray* GetKey(void);

    bool SetupOutDir(const QString &outdir);

}


#endif // UTILS_H
