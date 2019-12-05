#include "./include/public_lib.h" 
#include <vector>
#include "hello.h" 
#include "link.h" 
// #include "stack.h"

int main(void)
{
    char str[10] = " ramon";
    SimpleLink<int> Link;
    SimpleLink<int> Link2;
    int elem;

    hello(str);
    Link2.ReverseLink();
    Link.AddElem(5);
    Link.AddElem(6);
    Link.InsertLink(2, 4);
    Link.PrintLink();
    Link.ReverseLink();
    Link.PrintLink();
    Link.GetELem(2, elem);
    cout << "elem = " << elem << endl;
    Link2=Link;
    cout << "Link2" << endl;
    Link2.PrintLink();

    return 0;
}
