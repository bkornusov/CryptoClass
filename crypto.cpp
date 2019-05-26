#include "crypto.h"
#include <cstdlib>


Crypto::Crypto(ushort key, QString opseq, ushort charsiz)
    : m_key(key), m_OpSequence(opseq), m_CharSetSize(charsiz) { }

QString Crypto::encrypt(const QString& str) {
    randomPerm(str.length());
    QString current(str), newStr;
    for (ushort i = 0; i < m_OpSequence.length(); i++) {
        if (m_OpSequence[i] == 's') newStr = shift(current);
        else newStr = permute(current);
        current = newStr;
    }
    return newStr;
}
QString Crypto::decrypt (const QString& str) {
    randomPerm(str.length());
    QString current(str), newStr;
    for (ushort i = m_OpSequence.length(); i > 0; i--) {
        if (m_OpSequence[i-1] == 's') newStr = unshift(current);
        else newStr = unpermute(current);
        current = newStr;
    }
    return newStr;
}

QString Crypto::shift(const QString& str) {
    srand(m_key);
    const ushort sft(m_CharSetSize);
    int rand;
    QString cryptoStr;
    ushort cd, sCode;
    for (int i = 0; i < str.length(); ++i) {
        rand = limitedRand(m_CharSetSize);
        cd = str[i].unicode();
        sCode = (cd + rand) % sft ;
        cryptoStr[i] = QChar(sCode) ;
    }
    return cryptoStr;
}

QString Crypto::unshift(const QString& str) {
    srand(m_key);
    const ushort sft(m_CharSetSize);
    int rand;
    QString cryptoStr;
    ushort cd, sCode;
    for (int i = 0; i < str.length(); ++i) {
        rand = limitedRand(m_CharSetSize);
        cd = str[i].unicode();
        sCode = ((cd + sft) - rand) % sft ;
        cryptoStr[i] = QChar(sCode) ;
    }
    return cryptoStr;
}
QString Crypto::permute(const QString& str) {
    QString permStr;
    for (int i = 0; i < str.length(); ++i) {
        permStr += str.at(m_perm[i]);
    }
    return permStr;
}
QString Crypto::unpermute(const QString& str){
    QString permStr;
    for (int i = 0; i < str.length(); ++i) {
        permStr[m_perm[i]] = str[i];
    }
    return permStr;
}
int Crypto::limitedRand(int max) {
    return rand() % max ;
}
void Crypto::randomPerm(int n) {
    const int swaps(n*2);
    m_perm.clear();
    m_perm.resize(n);
    for (int i = 0; i < m_perm.length(); i++) {
        m_perm[i] = i;
    }
    srand(m_key);
    for (int i = 0; i < swaps; i++) {
        int j = limitedRand(n);
        int k = limitedRand(n);
        int temp = m_perm[j];
        m_perm[j] = m_perm[k];
        m_perm[k] = temp;
    }
}

int myRand(int min, int max) {
    return rand() % (max + 1 - min) + min;
}
