#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    // 3 multiplication
    cout << "********** Program 3 **********" << endl;
    int arr[10][10];
    const int row = 10;
    const int col = 10;
    int sumTable = 0;
    for (int i = 1;i <= row;i++) {
        for (int j = 1;j <= col;j++) {
            arr[i - 1][j - 1] = i * j;  // a
            sumTable += i * j;  // b
        }
    }
    
    cout << "  *|";
    for (int i = 1;i <= 10;i++) {
        cout << right
            << setw(4) << i;
    }
    cout << "\n--------------------------------------------" << endl;
    for (int i = 0;i < row;i++) {
        cout << setw(3) << i + 1 << "|";
        for (int j = 0;j < col;j++) {
            cout << right
                << setw(4) << arr[i][j];
        }
        cout << endl;
    }
    cout << "Sum of table = " << sumTable << endl;

    // 4
    cout << "********** Program 4 **********" << endl;
    cout << "sizeof(int) in bytes=" << sizeof(int) << ", bits=" << sizeof(int) * 8 << endl;
    cout << "sizeof(long int) in bytes=" << sizeof(long int) << ", bits=" << sizeof(long int) * 8 << endl;
    cout << "sizeof(long long int) in bytes=" << sizeof(long long int) << ", bits=" << sizeof(long long int) * 8 << endl;
    cout << "sizeof(float) in bytes=" << sizeof(float) << ", bits=" << sizeof(float) * 8 << endl;
    cout << "sizeof(double) in bytes=" << sizeof(double) << ", bits=" << sizeof(double) * 8 << endl;
    cout << "sizeof(long double) in bytes=" << sizeof(long double) << ", bits=" << sizeof(long double) * 8 << endl;
    
    // 6b
    cout << "********** Program 6 **********" << endl;
    int a = 0x0035FB84;
    int b = 0x0012F253;
    int c = a + b;
    cout << "c in hexadecimal = " << hex << c << endl;
    cout << "c in decimal = " << dec << c << endl;
    cout << "*******************************" << endl;
}

