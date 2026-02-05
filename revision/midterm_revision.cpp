#include <iostream>
using namespace std;

string myReverse(string str) {
    const char* cptr = str.c_str();
    char c[20];
    strcpy_s(c, str.c_str());
    for (int i= c.length; i>=0; i++) {
        c[i] 

}
int main()
{
    /*
    int a = 7, b=9;
    cout << (a | b) << endl;
    cout << (a && b) << endl;
    cout << (a || b) << endl;
    cout << !a << endl;
    cout << (a == b) << endl;
    */

    string str("hello my friend");
    str = myReverse(str);
    cout << str << endl;
    system("pause");
}


}


