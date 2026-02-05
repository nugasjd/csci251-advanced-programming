#include <iostream>
using namespace std; // standard library
int main()
{
    int i = 20;
    std::cout << "stored in address" << &i << std::endl;
    cout << "value of i = " << i << std::endl;

    int* ptr; // declare pointer to int
    ptr = &i; // ptr contains address of i
    cout << *ptr << endl;
    cout << "address inside ptr" << ptr << endl;
    cout << "value it is pointing to" << *ptr << endl;
    cout << "address where ptr is" << &ptr << endl; // address/reference operator

    *ptr = 40;  // changing value of i through ptr
    cout << "value of i = " << i << std::endl;
    system("pause");

}
