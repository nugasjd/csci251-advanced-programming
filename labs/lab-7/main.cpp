#include <iostream>
#include <string>
#include <vector>
using namespace std;

/* 1 without template class
class Pair {
    int x, y;
public:
    Pair() {
        int x = 0;
        int y = 0;
    }    
    Pair(int x, int y):x(x), y(y) {}
    Pair operator +(Pair p) {
        Pair temp;
        temp.x = p.x + this->x;
        temp.y = p.y + this->y;
        return temp;
    } 
    
    friend ostream& operator <<(ostream& o, Pair p) {
        o << "x=" << p.x << ", y=" << p.y << endl;
        return o;
    }
    int operator [](int value) {
        string exc = "Index out of bounds";
        if (value == 0) { return x; }
        else if (value == 1) { return y; }
        else throw exc;
    }
    Pair operator ++(int) {
        Pair temp;
        temp.x = x++;
        temp.y = y++;
        return temp;
    }
    Pair operator ++() {
        Pair temp;
        temp.x = ++x;
        temp.y = ++y;
        return temp;
    } */

// 2 template class 
template <class T>
class Pair {
    T x, y;
public:
    Pair() : x(0), y(0) {}
    Pair(T x, T y):x(x), y(y) {}
    Pair operator +(Pair<T> p) {
        Pair temp;
        temp.x = p.x + this->x;
        temp.y = p.y + this->y;
        return temp;
    } 
    friend ostream& operator <<(ostream& o, Pair<T> p) {
        o << "x=" << p.x << ", y=" << p.y << endl;
        return o;
    }
    T operator [](int num) {
        string exc = "Index out of bounds";
        if (num == 0) { return x; }
        else if (num == 1) { return y; }
        else throw exc;
    }
    Pair operator ++(int) {
        Pair temp;
        temp.x = x++;
        temp.y = y++;
        return temp;
    }
    Pair operator ++() {
        Pair temp;
        temp.x = ++x;
        temp.y = ++y;
        return temp;
    }
};

int main()
{
    cout << "***************** Program 1 *****************" << endl;
    Pair<int> p1(6, 9);
    Pair<int> p2(-5, 3);
    Pair<int> p3 = p1 + p2;
    cout << p1[0] << "  " << p1[1] << endl;
    try {
        cout << p1[2] << endl;
    }
    catch (string s) { cout << s << endl; }
   
    cout << "***************** Program 2 *****************" << endl;
    cout << "Double: " << endl;
    Pair<double> p4(5.7, 3.7);
    Pair<double> p5(8.9, 1.4);
    Pair<double> p6 = p4 + p5;
    cout << p4[0] << "  " << p4[1] << endl;
    
    cout << "Long long: " << endl;
    Pair<long long> p7(422343434678, 34587623434);
    Pair<long long> p8(978384536876, 20984958763);
    Pair<long long> p9 = p7 + p8;
    cout << p7[0] << "  " << p7[1] << endl;

    cout << "String: " << endl;
    Pair<string> p10("hello", "bye");
    Pair<string> p11("left", "right");
    Pair<string> p12 = p10 + p11;
    cout << p10[0] << "  " << p10[1] << endl;

    cout << "***************** Program 4 *****************" << endl;
    vector<string> v1;
    v1.push_back("Bread");
    v1.push_back("Coffee");
    v1.push_back("Tea");
    v1.push_back("Butter");
    v1.push_back("Juice");
    v1.push_back("Rice");
    v1.push_back("Sugar");
    v1.push_back("Honey");

    for (auto elem : v1) {
        cout << elem << endl;
    }

    vector <string>::iterator iter;  
    for (iter = v1.begin(); iter < v1.end();iter++) {
        cout << (*iter) << "  ";
    }

    v1.erase(v1.begin());
    v1.insert(v1.begin() + 1, "Salt");
    v1.insert(v1.begin() + 7, "Pepper");
    for (auto elem : v1) {
        cout << elem << endl;
    }
}
