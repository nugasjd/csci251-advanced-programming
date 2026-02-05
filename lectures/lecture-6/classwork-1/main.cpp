#include <iostream>
#include <string>
using namespace std;

class Pair {   
    double x, y;
public:
    Pair() { x = 0; y = 0; }
    Pair(double x, double y) : x(x), y(y) {}
    Pair operator +(Pair p2) {  // returns data type Pair
        Pair temp;
        temp.x = this->x + p2.x;
        temp.y = this->y + p2.y;
        return temp;
    } // operator overloading to add
    Pair operator -(Pair p2) {
        Pair temp;
        temp.x = this->x - p2.x;
        temp.y = this->y - p2.y;
        return temp;
    } // operator overloading to subtract
    void display() {
        cout << x << "   " << y << endl;    // no need to write 'this'
    }
    friend ostream & operator <<(ostream& out, Pair p) { // left obj is ostream and right 
        cout << p.x << "   " << p.y << endl;
        return out;
    } // operator overloading to print
};

class Student {
private:    // var is private by default
    int id;
    string name;
    double gpa;
public:
    Student() {}    // its good to include default/no parameter constructor
    Student(int id, string name, double gpa) {  // Student(int id, string name):name(name), id(id), gpa(gpa) { <-- this name equals name 
        this->id = id;
        this->name = name;
        this->gpa = gpa;
    } // parameter constructor
    
    friend void display(Student s);

    Student operator +(double d) {
        Student temp;
        temp.id = this->id;
        temp.name = this->name;
        temp.gpa = this->gpa + d;
        return temp;
    } // operator overloading to add GPA to student
    friend Student operator +(double d, Student s) {
        Student temp;
        temp.id = s.id;
        temp.name = s.name;
        temp.gpa = d+ s.gpa;
        return temp;
    } // friend operator to allow double + Student
    friend ostream& operator <<(ostream out, Student s) {
        out << s.id << "   " << s.name << "   " << s.gpa << endl;
        return out;
    } // operator overloading to print
    
};

// should write this after the class
void display(Student s) {
    cout << s.id << "   " << s.name << endl;
}

int main()
{
    Student s1(6354, "Jewel", 3.2);      // when creating object, cannot access constructor if its private
    display(s1);

    // update gpa after using overloaded + operators
    // cout << s1 << endl;
    s1 = s1 + 0.1;
    s1 = .3 + s1;

    // create and manipulate pair objects
    Pair p1(5.5, 7.8);
    Pair p2(39, 9.2);
    cout << "Adding 2 pairs:" << endl;
    Pair p3 = p1 + p2;
    p3.display();
    p3 = p1 - p2;
    cout << "Displaying using the << " << endl;
    cout << "p3=" << p3 << "p1=" << p1 << endl; // cout=ostream object
    /* << -insertion operator doesnt know how to display user types so it must be displayed in the class.aka operator overloading
    cout << p1; <-- returns void
    */ 
    system("pause");
}


