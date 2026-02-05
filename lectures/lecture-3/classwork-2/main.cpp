#include <iostream>
#include <fstream>  // declare library fstream
#include <string>   // contains getline func
#include <sstream>  // for istringstream
using namespace std;

double do_operation(int a, char op, int b) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return (a * b);
        case '/': return (a*1.0 / b*1.0);
        default: cout << "Illegal operation";
    }   // switch
}   // function

int main()
{    
    string str = "Hello how are you";
    int ipos = str.find("you");
    cout << "ipos = " << ipos << endl;
    string str2 = "tchan";
    str.replace(ipos, 3, str2, 0, str2.length()-1);
    cout << "str = " << str << endl;

    // formatted i / o method
    int a;
    double d;
    string str1;
    cin >> a >> str1 >> d;
    cout << a << "  " << str1 << "  " << d;

    // file - textOperation
    ifstream in;     // opens a file for reading/input. declares file and opens it
    in.open("textOperation.txt");
    if (!in) { 
        cout << "Cannot open the text file ***textOperation.txt***" << endl;
        system("pause");
        return 1;
    }
    string myline;

    getline(in, myline, '\n');
    cout << myline << endl;

    int operand1, operand2;
    char operation;
    while (getline(in, myline, '\n')) {
        istringstream is(myline);   // instead of putting cin,  write is
        is >> operand1 >> operation >> operand2;
        double result = do_operation(operand1, operation, operand2);
        cout << myline << " = " << result << endl;
    }
    
    // file - myFile
    ifstream in;
    in.open("myFile.txt");
    if (!in) {
        cout << "Cannot open the text file ***myFile.txt***" << endl;
        system("pause");
        return 1;
    }
    string myline;

    int id, num;
    string name, place;
    while (getline(in, myline, '\n')) {
        istringstream is(myline);
        is >> id >> name >> place >> num;
        cout << "Result = " << id << ":" << num << endl;
    }

    system("pause");
}
