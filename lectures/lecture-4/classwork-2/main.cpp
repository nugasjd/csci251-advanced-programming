#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
using namespace std;

int main()
{
    string str = "245";
    int num = stoi(str);
    cout << "Num=" << num << endl;

    // successfully open a text file into a stream
    ifstream in("filename.txt");
    if (!in) {
        cout << "Cannot open text file" << endl;
        system("pause");
        return 1;
    }

    cout << "File successfully opened" << endl;

    // 7a
    string str1 = "45.7";
    float flt1 = stof(str1);
    cout << "Float num = " << flt1 << endl;

    // 7b
    str1 = "45";
    int num1 = stoi(str1);
    cout << "Integer num = " << num1 << endl;

    // 7c
    char arr[] = "super";
    string strArr(arr);
    cout << "String = " << strArr;

    // 7d
    string str2 = "hello how are you";
    const char* newStr = str2.c_str();
    cout << newStr << endl;

}



