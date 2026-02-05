#include <iostream>
using namespace std;

// 1
int divis(int a, int b) {
    string exc = "Cannot divide by 0";
    if (b == 0) throw exc;
    return a / b;
}

// 2
double getA_positive_number() {
    string exc = "It is not a positive number";
    double pos;
    cout << "Enter a positive number:" << endl;
    cin >> pos;
    if (pos >= 0) { return pos; }
    else throw exc;
}

/* 3 Part one
class Number {
private:
    int theNumber;
public:
    Number():theNumber(theNumber) {}
    Number(int n) { theNumber = n; }
    void display() { cout << theNumber << endl; }
    int getNumber() { return theNumber; }
    friend ostream& operator << (ostream& o, Number n) {
        o << n.theNumber << endl;
        return o;
    }
    Number operator ++(int) {
        return theNumber++;
    }
    Number operator ++() {
        return ++theNumber;
    }
    Number operator +(int num) {
        return theNumber + num;
    }
    friend Number operator +(int num, Number n) {
        return num + n.theNumber;
    }
    Number operator -(int num) {
        return theNumber - num;
    }
    friend Number operator -(int num, Number n) {
        return num - n.theNumber;
    }
    Number operator ==(int num) {
        return theNumber == num;
    }
}; */

// 3 Part two
template <class T>
class Number {
private: 
    int theNumber;
public:
    Number() :theNumber(theNumber) {}
    Number(T n) { theNumber = n; }
    void display() { cout << theNumber << endl; }
    int getNumber() { return theNumber; }
    friend ostream& operator << (ostream& o, Number<T> n) {
        o << n.theNumber << endl;
        return o;
    }
    Number operator ++(T) {
        return theNumber++;
    }
    Number operator ++() {
        return ++theNumber;
    }
    Number operator +(T value) {
        return theNumber + value;
    }
    friend Number operator +(T value, Number<T> n) {
        return value + n.theNumber;
    }
    Number operator -(T value) {
        return theNumber - value;
    }
    friend Number operator -(T value, Number<T> n) {
        return value - n.theNumber;
    }
    Number operator ==(T value) {
        return theNumber == value;
    }
}; 


int main()
{
    cout << "*************** Program 1 ***************" << endl;
    try {
        cout << divis(7, 1) << endl;
        cout << " message 1" << endl;
        cout << divis(7, 0) << endl;
        cout << " message 2 " << endl;
    }
    catch (string s) { cout << s << endl; }
    
    cout << "*************** Program 2 ***************" << endl;
    while (1)
    {
        try {
            cout << getA_positive_number();
            system("pause");
            break;  // break if successful
        }
        catch (string s) { cout << s << endl; }
        
    }
    cout << "The positive number was read successfully " << endl;

    cout << "*************** Program 3 ***************" << endl;
    Number<int> n1(123);
    Number<int> n2;

    cout << n1 << endl;
    n2 = n1++;
    cout << n2 << endl;
    n2 = ++n1;
    cout << n2 << endl;
    n2 = n1 + 77;
    cout << n2 << endl;
    n2 = 77 + n1;
    cout << n2 << endl;
    n2 = n1 - 77;
    cout << n2 << endl;
    n2 = 77 - n1;
    cout << n2 << endl;
    cout << n1 == 77;

    Number<long long> n3(1234567765432);
    Number<long long> n4;
    cout << n3 << endl;
    n4 = n3++;
    cout << n4 << endl;
    n4 = ++n3;
    cout << n4 << endl;
    n4 = n3 + 77;
    cout << n4 << endl;
    n4 = 77 + n3;
    cout << n4 << endl;
    n4 = n3 - 77;
    cout << n4 << endl;
    n4 = 77 - n3;
    cout << n4 << endl;
    cout << n3 == 77;

    Number<double> n5(94.7);
    Number<double> n6;
    cout << n5 << endl;
    n6 = n5++;
    cout << n6 << endl;
    n6 = ++n5;
    cout << n4 << endl;
    n6 = n5 + 77;
    cout << n6 << endl;
    n6 = 77 + n5;
    cout << n6 << endl;
    n6 = n5 - 77;
    cout << n6 << endl;
    n6 = 77 - n5;
    cout << n6 << endl;
    cout << n5 == 77;

    Number<char> n7('94.7');
    Number<char> n8;
    cout << n7 << endl;
    n8 = n7++;
    cout << n8 << endl;
    n8 = ++n7;
    cout << n8 << endl;
    n8 = n7 + 77;
    cout << n8 << endl;
    n8 = 77 + n7;
    cout << n8 << endl;
    n8 = n7 - 77;
    cout << n8 << endl;
    n8 = 77 - n7;
    cout << n8 << endl;
    cout << n7 == 77;
}
