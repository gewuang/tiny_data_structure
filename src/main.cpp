#include <iostream>
#include "hello.h" 
#include "link.h" 

using namespace std;

int main(void)
{
    char str[10] = " ramon";
    SimpleLink<int> Link;

    hello(str);
    Link.AddElem(5);
    Link.AddElem(6);
    Link.PrintLink();

    return 0;
}
