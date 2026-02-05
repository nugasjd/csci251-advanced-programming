#include <iostream>
#include <memory>
using namespace std;

// Memory leak using raw pointer
void memory_leak_raw() {
    int myint = 8;
    int* ptr = &myint;
    return;
}

// Preventing memory leak using smart pointer
void memory_leak_smart() {
    int myint = 8;
    int* ptr = &myint;
    delete (ptr);
}

int main()
{
    memory_leak_raw();
    memory_leak_smart();
}



