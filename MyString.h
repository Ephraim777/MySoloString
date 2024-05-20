
#ifndef ONESTR_MYSTRING_H
#define ONESTR_MYSTRING_H
#include "Counter.h"
class MyString {
public:
    Counter *m_pMyCounter;
    MyString();
    MyString(const char * ptr);


    MyString(const MyString &oth);
    MyString (MyString && oth);
    MyString& operator=(const MyString &oth);
    MyString & operator = (MyString && oth);


    ~MyString();


    const char*Getstr();

    static void PrintStrs();

    static void ChangeRegister();

    static void SortAlphavit();

};
#endif
