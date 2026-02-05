#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    // 1
    ifstream in;
    in.open("file1.txt");
    if (!in) {
        cout << "File not found" << endl;
    }
    string str;
    getline(in, str, '\0');
    cout << str << endl;

    // 2
    int ipos = str.find("better", 0);
    cout << "Position of the string better: " << ipos << endl;

    // 3
    ipos = str.find("sytax", 0);
    cout << "Position of the string sytax: " << ipos << endl;
    ipos = str.find("syntax", 0);
    cout << "Position of the string syntax: " << ipos << endl;
}



