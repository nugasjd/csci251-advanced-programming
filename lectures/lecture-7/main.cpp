#include <iostream>
using namespace std;

class Pair {
    int x, y; // member data, private
public:
    /*
    parameter constructors - w 0-2(or more) parameters
    */
    Pair(int x = 0, int y = 0) {
        this->x = x;
        this->y = y;
    }
    // Pair(int x) { this->x = x; }     // mistake

    // friend, arguments and return <-- include
    // can be implemented outside of class, but dont include friend
    // this ptr automatically goes to member function, but in friend func below theres no this ptr
    // friend func can access member data through objects only
    friend ostream& operator <<(ostream& o, Pair p) {
        o << p.x << "   " << p.y << endl;
        return o;
    }
    int operator [](int i) {    // left is this ptr so no need to include in parameter
        string message = "Index out of rangw";
        if ((i < 1) || (i > 2)) throw (message);
        if (i == 1) return x;
        if (i == 2) return y;
        // may be error in compiler 
    }
    Pair operator ++() {  // pair on the right will be done automatically (so no need to put it in parameter
        Pair temp;
        temp.x = ++x;
        temp.y = ++y;
        return temp;
    }
    // not sure if i should leave int on the parameter
    Pair operator ++(int) {  // pair on the right will be done automatically (so no need to put it in parameter
        Pair temp;
        temp.x = x++;
        temp.y = y++;
        return temp;
    }

};

int main()
{
    try {
        Pair p1(-3, 4);
        Pair p2;
        Pair p3(29);
        cout << p1 << endl;     // left to right <-- ostream, use a friend func
        cout << p1[1];  // return x. left is object of type Pair, right is an int
        cout << p1[2];  // return y
        cout << p1[3];  // throws exception
        // << is a call to function
    }
    catch (string s) { cout << s << endl; }
    catch (char* s) { cout << s << endl; }
    catch (...) { cout << "Other type is caught"; } // default catch
    cout << "I continue my work as usual" << endl;
    
    // have to redeclare p1
    Pair p1(34, 43);
    // p1++;
    Pair p3 = ++p1;   // right to left
    cout << p1 << p3 << endl;
    Pair p4 = p1++;
    cout << "P++= " << p1 << p4 << endl;

    system("pause");
}


