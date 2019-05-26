#include "crypto.cpp"

#include <QTextStream>
#include "crypto.h"

//main.cpp

// Batyr Kornusov Homework Assignment 2
// Crypto class from Chapter 5.12
// this file stores the main function for the Crypto class assignment
// last modified: 10:28 PM, 05.09.2019

static QTextStream cout(stdout);

int main()  {
   QTextStream cout(stdout);
   QString str1 ("asdfghjkl;QWERTYUIOP{}}|123456&*()_+zxcvnm,,, ./?."),
           str2;
   cout << "Original string: " << str1 << endl;
   cout << "length: " << str1.length() << endl;
   QString seqstr("pppp");
   ushort key(12579);
   ushort charsiz(str1.length());
   Crypto crypt(key, seqstr, charsiz);
   str2 = crypt.encrypt(str1);
   cout << "Encrypted string: " << str2 << endl;
   cout << "Recovered string: " << crypt.decrypt(str2) << endl;
}
