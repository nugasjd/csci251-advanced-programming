#include <iostream>
#include <fstream>  // declare library fstream
#include <string>   // contains getline func
#include <sstream>  // for istringstream
using namespace std;

int main()
{
    // ofstream - for output
    ifstream in;    // opening file
    in.open("mytext.txt");  
    // always check if file has been opened or not
    if (!in) {  // if file doesnt exist
        cout << "Cannot open the text file ***mytext.txt***" << endl;
        system("pause");
        return 1;
    }
    
    string str;
    getline(in, str, '\0'); // delimiter '\0' - reads until eof (end of file)
    cout << str << endl;    // outputs content of file
    cout << "Empty? " << str.empty() << endl;    // empty (function) - 0 false, 1 true
    cout << "Length: " << str.length() << endl;
    
    // using substr method
    string str1 = "AB345678912";
    str1 = str1.substr(2, 4);   // index/position always starts counting from 0
    cout << str1 << endl;

    // using find method - searching for a str
    int ipos;
    string str2 = "finding nemo";
    ipos = str.find("nemo", 0); // find str starting from position 0, case-sensitive
    cout << "String found at index " << ipos << endl;   // if ipos -1 then not found
    
    int ipos = 0;
    while ((ipos = str.find("class", ipos)) >= 0) { // put brackets accordingly
        cout << "ipos: " << ipos << endl;
        ipos++;
    }

    system("pause");
}

