#include <iostream>
#include <string>
#include <map>
#include <iterator>
#include <algorithm>
#include <vector>
using namespace std;

class A {
    int amount;
    string str;
    int* ptr;
public:
    A() {}
    A(int amount, string str) :amount(amount), str(str) {
        ptr = new int();
    }

    friend ostream& operator <<(ostream& o, A a) {
        o << a.amount << "  " << a.str << endl;
        return o;
    }
    A operator +(A a) { // error here
        A sum;
        sum.amount = this->amount + a.amount;
        sum.str = this->str + a.str;
        return sum;
    }
    string operator [](int i) {
        string msg = "Index out of range";
        if ((i < 1) || (i > 2)) throw (msg);
        if (i == 1) {
             string amountI = to_string(this->amount);
             return amountI;
        }
        if (i == 2) return this->str;
    }
};

int f1()
{
    static int num = 6;
    num = num + 4;
    return ++num;
}

int f2()
{
    static int num = 6;
    num = num + 4;
    return num++;
}


// 6
template <class T>
class Number
{
private:
    T theNumber;
public:
    Number(T n) { theNumber = n; }
    void display() { cout << theNumber << endl; }
    T getNumber() { return theNumber; }
};

// 8
class Person
{
    string name;
public:
    //Person() { name = "*****"; }
    Person(string name) :name(name) {}
    virtual void display1() { cout << " Base display1" << name << endl; }
    string getName() { return name; }
    void display2() { cout << " Base display2" << name << endl; }
};

class Student :public Person
{
    string major;       
    int Sid;
public:
    //Student():Person() {}
    Student(string name, string major, int id) :Person(name) { this->major = major; this->Sid = id; }
    void display1() { cout << " Derived " << Person::getName() << "  " << major << " " << Sid << endl; }
    void display3() { cout << " Derived  Student" << Person::getName() << "  " << major << " " << Sid << endl; }
};


class Teacher :public Person
{
    string rank;
public:
    Teacher(string name, string rank) :Person(name), rank(rank) {};
    void display1() { cout << " Derived Teacher " << Person::getName() << "  " << rank << endl; }
};


int main()
{
    // 1
    A a1(20, "hello");
    A a2(30, "super");
    A a4(a1);
    A a3 = a1 + a2;
    cout << a3 << endl; // returns object of type A

    try {
        cout << a1 << endl;
        cout << a1[1] << endl;  // display 20
        cout << a2[2] << endl;  // display "hello"
    }
    catch (string s) { cout << s << endl; }

    // 2
    cout << " working with f1 " << endl;
    for (int k = 1; k <= 4; k++)    cout << f1() << endl;
    cout << " working with f2 " << endl;
    for (int k = 1; k <= 4; k++) cout << f2() << endl;
    
    // 3
    map<char, string> m1;
    m1.insert({ 'a', "apple" });
    m1.insert({ 'c', "cherry" });
    m1.insert({ 'k', "kiwi" });
    m1.insert({ 'b', "banana" });
    m1.insert({ 'o', "orange" });
    m1.insert({ 'l', "lemon" });

    cout << "Using auto:" << endl;
    for (auto elem : m1) {
        cout << elem.first << " " << elem.second << endl;
    }
    
    cout << "Using iter:" << endl;
    map<char, string>::iterator iter;
    for (iter = m1.begin();iter != m1.end();iter++) {
        cout << (*iter).first << "  " << (*iter).second << endl;
    }

    cout << "Removing the 1st elem:" << endl;
    m1.erase(m1.begin());

    cout << "Removing the 4th elem:" << endl;
    m1.erase('k');

    cout << "Removing the last elem:" << endl;
    m1.erase('o');

    cout << "Using auto:" << endl;
    for (auto elem : m1) {
        cout << elem.first << " " << elem.second << endl;
    }

    // 4
    vector<int> v1;
    v1.push_back(45);
    v1.push_back(34);
    v1.push_back(6);
    v1.push_back(78);
    v1.push_back(23);
    v1.push_back(5);

    cout << "Using auto:" << endl;
    for (auto elem : v1) {
        cout << elem << " ";
    }
    cout << endl;

    cout << "Using iterator:" << endl;
    for (vector<int>::iterator iter = v1.begin(); iter != v1.end();iter++) {
        cout << *iter << " ";
    }
    cout << endl;

    cout << "Using copy to ostream:" << endl;
    copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    cout << "Inserting 2 new elements: " << endl;
    v1.insert(v1.begin(), 8);
    v1.insert(v1.begin() + 1, 9);
    cout << "Using auto:" << endl;
    for (auto elem : v1) {
        cout << elem << " ";
    }
    cout << endl;

    sort(v1.begin(), v1.end());
    cout << "Sorted vector:" << endl;
    for (auto elem : v1) {
        cout << elem << " ";
    }
    cout << endl;

    cout << "Removing the 1st elem:" << endl;
    v1.erase(v1.begin(), v1.begin() + 1);

    cout << "Removing the 4th elem:" << endl;
    v1.erase(v1.begin() + 2, v1.begin() + 3);   // deleting 4th elem after 1st is deleted

    cout << "Removing the last elem:" << endl;
    v1.erase(v1.end() - 1);

    cout << "Using auto:" << endl;
    for (auto elem : v1) {
        cout << elem << " ";
    }
    cout << endl;

    // 6
    Number<int> a(2);
    a.display();
    int j = a.getNumber();

    // 8
    cout << "Inheritance - Polymorphism:" << endl;
    Person p1("Mahfouz");
    Student s1("Abdel Hay", "CS", 8767);
    p1.display1();
    s1.display1();
    s1.display2();
    //p1.display3();
    s1.display3();



    //   *  Working With Base pointers  pointing to base object
    Person* bPtr;
    bPtr = &p1;
    bPtr->display1();
    bPtr->display2();

    //  bPtr->display3();

// * Working with Base  pointers pointing to derive object  
    cout << "   base pointer point to Derive " << endl;
    bPtr = &s1;
    bPtr->display1();
    bPtr->display2();
    //bPtr->display3();  

// * Working with Derive pointers
    Student* dPtr;
    //dPtr = &p1;  derive pointer cannot point to a base object
    cout << "   Derive pointer point to Derive " << endl;
    dPtr = &s1;
    dPtr->display1();       // derive
    dPtr->display2();       // goes up to the base
    dPtr->display3();        // derive

    // dynamic Polymorphism

    cout << "  *****   Achieving Polymorphism  **************" << endl;
    Person* bptr2[] = { &p1,&s1,new Person("Alex"), new Teacher("halim", "Professor"), new
                                        Student("Munala","CS",999) };
    for (auto elem : bptr2)
    {
        elem->display1();
    }         // polymorphism would be achieved only if declared as virtual

    system("pause");
}
