#include <iostream>
using namespace std;

template <class T>
void swapp(T &a, T &b) {   // T is a generic func/anything
    T temp = a;
    a = b;
    b = temp;
} // generic function -  can swap with different data types

template <class T>
void maxx(T& a, T& b) {
    if (a > b) { cout << a << " is the maximum" << endl; }
    else { cout << b << " is the maximum" << endl; }
}

class Student {
    int id;
    string name;
    static int Nstudents;

public:
    Student() { Nstudents++; };
    Student(int idd, string name) {
        this->id = idd;
        (*this).id = idd;
        this->name = name;
        Nstudents++;
    } // constructor
    
    void display() { 
        cout << "id:" << id << "  name:" << name << endl;
        cout << Nstudents << endl;
        cout << this->id;   // this can be passed
    }

    static void display2() {
        cout << Nstudents << endl;
        // cout << this->id;  <-- this cannot be passed
    } // static function

    
};

class Demo {
public:
    Demo& do1() { cout << "Calling do1()..." << endl; return *this; };
    Demo& do2() { cout << "Calling do2()..." << endl; return *this; };
    int do3() { cout << "Calling do3()..." << endl; return 5; };
};

int Student::Nstudents = 0;  // private. Nstudent belongs to Student

int main()
{
    /* constant pointers
    int a = 27;
    int b = 3;
    int* ptr;
    ptr = &a;
    cout << *ptr << endl;
    ptr = &b;
    cout << *ptr << endl;
    // using int* const ..
    int* const ptr2 = &a;
    // cannot write ptr2 = &b;
    */

    // creating object
    Student s1(312, "Ayman");
    s1.display();

    /* doesnt work
    cout << s1.id << endl;
    cout << s1.Nstudents << endl;
    cout << Student::Nstudents << endl; */
    Student::display2();

    // using the swap func
    int a = 30;
    int b = -50;
    swapp(a, b);    
    // dont use swap because it will be overloaded since there is already another existing function of swap
    cout << a << "  " << b << endl; // a callby value
    // call reference by using & in the func parameters

    string str1 = "hello";
    string str2 = "bye";
    swapp(str1, str2);

    // demo function
    cout << "Demo: " << endl;
    Demo d1;
    d1.do1().do2();
    d1.do1().do3();

    // using max function
    maxx(a, b);
    double c = 5.7;
    double d = 9.8;
    maxx(c, d);

    system("pause");
}

