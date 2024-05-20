

#ifndef ONESTR_COUNTER_H
#define ONESTR_COUNTER_H
#include "string.h"

#include <iostream>

class Counter{
public:
    char * m_pStr;
    size_t  m_nOwners;
    Counter*next;
    static Counter * Head;
    static size_t m_curCounters;
    Counter(const char * str);


    ~Counter();

    void addOwner();

    void removeOwner() ;

    static Counter*FindCounter(const char * str);

    static void PrintAll();

    static void ChangeRegister();

    static void SortAlphavit();


};

#endif
