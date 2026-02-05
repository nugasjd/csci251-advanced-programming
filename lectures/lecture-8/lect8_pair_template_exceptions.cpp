#include <iostream>
#include <vector>
using namespace std;

// class template and exceptions
template <class T>
class Pair{     
    T x, y;
public:
    Pair(T x = 0, T y = 0) : x(x), y(y) {}
    friend ostream& operator << (ostream& o, Pair<T> p) {  // parameters for cout<<p1= stream and object. Called prototype if not implemented
        o << p.x << "  " << p.y << endl;
        return o;   // remember to return stream
    }
        T operator [] (int value) { 
        string exc = "out of bounds";
        if (value == 0) return x;, 
        else if (value == 1) return y;
        else throw exc;   // throw exception if value is out of bounds. Must throw a data type not 'exception'
    }
    
}; 

    /* other method to overload + operator
    Pair operator +(const Pair& p) const{
        return Pair(x+p.x, y+p.y);}
    bool operator ==(const Pair& p) const{
        if (x==p.x && y==p.y) {
            return true; }
        else {return false;}
    } */

float divide(int a, int b) {
    if (b == 0) throw ("Cannot divide by 0");   // ("byebye") is constant. constant is a type
    return (a * 0.1 / b * 0.1); // dividing by 0 will make the float number , so make an exception
}

int main() {
    // class template and exceptions
    Pair<int> p1(9, 5);     // Pair is a template , so must declare a type in <>
    Pair<int> p2(-7, 2);

    cout << p1 << endl; // left to right. use friend func
    cout << p1[0] << p1[1] << endl; // p1[0] <-- left=p1, right=int.  since left is an obj, no need to write it in parameter bcuz this ptr of this is pointing to obj
    try {
        cout << p1[5] << endl;  // should return "out of bounds"
        cout << "What's happening??" << endl;
    }
    catch (int im) { cout << im << endl; }
    catch (string s) { cout << s << endl; } // since exc is string use string in the catch block

    Pair<double> p3(2.8, 6.8);
    cout << p3 << endl;
    cout << p3[1] << endl;

    // 
    try {
        cout << divide(7, 9) << endl;
        cout << divide(29, 0) << endl;
        cout << "Both have been executed" << endl;
    }
    catch (string s) { cout << s << endl; }
    catch (char* ss) { cout << ss << endl; }
    catch (const char* ss) { cout << ss << endl; }
    

    // STL (vectors)
    vector <string> v1;
    v1.push_back("Shair");
    v1.push_back("Hassan");
    v1.push_back("Abdul Rahim");
    v1.push_back("Rizan");
    v1.insert(v1.begin(), "hello"); // not efficient
    v1.insert(v1.end(), "bye");
    v1.erase(v1.begin(), v1.end());
    v1.erase(v1.begin(), v1.begin()+1);     // deleting 1st element

    for (auto elem : v1) {
        cout << elem << "  ";
    }
    cout << endl;

    vector <string>::iterator iter;  // declaring an iterator
    for (iter = v1.begin(); iter < v1.end();iter++) {
        cout << (*iter) << "  ";
    }
}
