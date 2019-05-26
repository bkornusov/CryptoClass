#ifndef CRYPTO_H
#define CRYPTO_H

#include <QString>
#include <QVector>
#include <cstdlib>

//crypto.h

// Batyr Kornusov Homework Assignment 4
// Crypto class from Chapter 5.12
// this file stores the class Crypto
// last modified: 10:28 PM, 05.09.2019


class Crypto {
private:
    QString m_OpSequence;
    ushort m_CharSetSize;
    ushort m_key;
    QVector<int> m_perm;
public:
    Crypto(ushort key, QString opseq, ushort charsiz);
    QString encrypt(const QString& str);
    QString decrypt (const QString& str);
    QString shift(const QString& str);
    QString unshift(const QString& str);
    QString permute(const QString& str);
    QString unpermute(const QString& str);
    int limitedRand(int max);
    void randomPerm(int n);
};

#endif // CRYPTO_H
