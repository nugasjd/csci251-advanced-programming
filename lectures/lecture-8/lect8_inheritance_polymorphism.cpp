#include <iostream>
using namespace std;

class Person {
protected:
    string name;
public:
    Person(string name):name(name) {}
    virtual void display1() { cout << "Base display 1:" << name << endl; }  // add virtual to achieve polymorphism
    void display2() { cout << "Base display 2:" << name << endl; }
};

class Student :public Person {
    int stID;
public:
    Student(int stID, string name):Person(name) {
        this->stID = stID;
    }
    void display1() { cout << "Derive (student) display 1:" << stID << "  " << name << endl; }
    void display3() { cout << "Derive display 3:" << stID << endl; }
};

class Teacher :public Person {
    string rank;
public:
    Teacher(string rank, string name) : Person(name) { this->rank = rank; }
    void display1() { cout << "Derive (teacher) display 1:" << rank << "  " << name << endl; }
    void display3() { cout << "Derive display 3:" << rank << endl; }
};

int main()
{
    Person p1("Reza");
    p1.display1();

    Student s1(876, "Alisha");
    s1.display1();
    s1.display2();

    // p1.display1(3); // allows to grab student no rank
    s1.display3();



    cout << "****************** 2nd part ********************" << endl;
    // base ptrs and derived ptrs
    Person* Bptr;
    Bptr = &p1;
    Bptr -> display1();
    Bptr->display2();
    // Bptr->display3();   // gives error

    Bptr = &s1;
    Bptr->display1();
    Bptr->display2();
    // Bptr->display3();   // has to be in the base
    

    cout << "****************** 3rd part Polymorphism ********************" << endl;
    // polymorphism
    Person* Pptrarr[] = { new Person("Abdul Rahim"), new Student(888, "Afwan"), new Teacher("Professor", "Halim"), &p1, &s1 };
    for (auto elem : Pptrarr) {
        elem->display1();
    }
}

