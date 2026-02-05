#include <iostream>
#include <string>
using namespace std;


class Student {
    // default - private
private:
    int id;
    string name;
    static int howmany; // static member functions cannot access private variables

public:
    // static int howmany;     // its better to keep it public
    Student() { howmany++; }    // default constructor
    Student(int id, string name) {
        (*this).id = id;    // or this->id=id;
        this->name = name;
        howmany++;
    }   // constructor

    void display() { cout << id << "   " << name << "   " << howmany << endl; } // non-static method - can display member and class data

    static void display2() { cout << howmany << endl; } // static/class function - can only access static var, not member data


};

int Student::howmany = 0;   // initialize static variables outside the main function and class
// static var can be accessed by class scope

int main()
{
    Student s(123481, "Ahmed");     // static object. not dynamic  
    s.display();
    cout << "howmany: " << s.howmany << "   " << Student::howmany << endl;
    // static var can be accessed by 'object.method'
    cout << s.id << "   " << Student::id << endl;  // id is not public. if id is public, you cant use Student::id
    
    int a = 7;
    int b = 9;
    cout << (a | b) << endl;
    cout << (a ^ b) << endl;  // (0 if bits are equal     1 otherwise)
    cout << (a & b) << endl;
    cout << ~a << endl;
    cout << (a && b) << endl;
    cout << (a || b) << endl;
    cout << !a << endl;

    cout << (a == b) << endl;

    system("pause");
}
