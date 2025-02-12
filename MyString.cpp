#include "MyString.h"
    MyString::MyString(const char * ptr){
        m_pMyCounter=Counter::FindCounter(ptr);
        if (m_pMyCounter==nullptr){
            m_pMyCounter= new Counter(ptr);
        }else{
            m_pMyCounter->addOwner();
        }
    }
    MyString::MyString(const MyString &oth){
        m_pMyCounter=oth.m_pMyCounter;
        m_pMyCounter->addOwner();

    }
    MyString::MyString(MyString && oth){
    m_pMyCounter = oth.m_pMyCounter;
    oth.m_pMyCounter = nullptr;
}
MyString::MyString(){
    this->m_pMyCounter = nullptr;
}
   MyString&  MyString::operator=(const MyString &oth){
        if(this== &oth){
            return *this;
        }
        if (oth.m_pMyCounter != nullptr){
        if(m_pMyCounter != nullptr){
        m_pMyCounter->removeOwner();}

        m_pMyCounter=oth.m_pMyCounter;
       if(m_pMyCounter != nullptr){
        m_pMyCounter->addOwner();}}
        return *this;

    }
MyString&  MyString::operator=( MyString &&oth){
    if(this== &oth){
        return *this;
    }
    if (oth.m_pMyCounter != nullptr){
        if(m_pMyCounter != nullptr){
            m_pMyCounter->removeOwner();}

        m_pMyCounter=oth.m_pMyCounter;
            oth.m_pMyCounter= nullptr;


} return *this;}


    MyString::~MyString(){
        if(m_pMyCounter != nullptr){
        m_pMyCounter->removeOwner();}
    }
    const char*MyString::Getstr(){
        return m_pMyCounter->m_pStr;
    }
     void MyString::PrintStrs(){
        Counter::PrintAll();
    }
     void MyString::ChangeRegister(){
        Counter::ChangeRegister();
    }
    void MyString::SortAlphavit(){
        Counter::SortAlphavit();
    }
