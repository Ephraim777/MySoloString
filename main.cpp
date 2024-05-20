#include "MyString.h"
using namespace std;


Counter* Counter:: Head= nullptr;
size_t Counter:: m_curCounters=0;
int main()
{

    MyString c("s");
    MyString f ("s");
    MyString d("privet");
    MyString f("s");
    MyString f1 ("2");
    MyString f2;
    f1 = std::move(c);



   MyString::ChangeRegister();
   MyString::SortAlphavit();
   MyString::PrintStrs();

    return 0;
}