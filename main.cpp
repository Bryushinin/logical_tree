#include "logic_header.h"
int main()
{
    tree* A=Convert(Read());
    Print(A,5);
    cout<<endl<<"The result is: "<<Computing2(A);
    return 0;
}
