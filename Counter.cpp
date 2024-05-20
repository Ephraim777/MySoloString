#include "Counter.h"



    Counter::Counter(const char * str){
        m_pStr = new char[strlen(str)+1];
        strcpy(m_pStr,str);
        m_nOwners =1;
        next = nullptr;
        if(Head == nullptr){
            Head = this;
        } else{
            Counter* temp = Head;

            while(temp->next!= nullptr){

                temp= temp->next;
            }

            temp->next = this;

        }
        m_curCounters++;

    }

    Counter::~Counter(){
        delete [] m_pStr;
        m_curCounters--;

    }
    void Counter::addOwner(){
        m_nOwners++;
    }
void Counter::removeOwner() {
    if (--m_nOwners == 0) {
        Counter *temp = Head;
        Counter *prev = nullptr;
        while (temp != nullptr && temp != this) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == this) {
            if (prev != nullptr) {
                prev->next = this->next;
            } else {
                Head = this->next;
            }
        }
        delete this;
    }
}    Counter* Counter::FindCounter(const char * str){
        Counter * temp = Counter::Head;
        while(temp!=nullptr){
            if(strcmp(temp->m_pStr,str)==0){
                return temp;

            }
            temp=temp->next;
        }
        return nullptr;
    }
     void Counter::PrintAll(){
        Counter * temp = Counter::Head;
        while(temp!= nullptr){
            std::cout<< "Строка: \n";
            std::cout<< temp->m_pStr<< std::endl;
            std::cout<< "Владельцы: \n";
            std::cout<< temp->m_nOwners<< std::endl;
            temp= temp->next;
        }

    }
void Counter::ChangeRegister(){
    Counter * temp = Counter::Head;
    while (temp!= nullptr){
        int length = strlen(temp->m_pStr);
        for (int i=0; i<length; i++){
            if( temp->m_pStr[i] >= 'A' && temp->m_pStr[i] <= 'Z'){
                temp->m_pStr[i]+=32;}
            else if(temp->m_pStr[i] >= 'a' && temp->m_pStr[i] <= 'z'){
                temp->m_pStr[i]-=32;
            }
        }
        temp=temp->next;
    }
}
    void Counter::SortAlphavit(){
        for(Counter * current= Counter::Head; current!=nullptr; current=current->next){

            for (Counter *next_ = current->next; next_!=nullptr; next_=next_->next){
                if (strcmp(current->m_pStr,next_->m_pStr) >0){
                    std::swap(current->m_pStr,next_->m_pStr);
                    std::swap(current->m_nOwners,next_->m_nOwners);
                }
            }
        }




    }


