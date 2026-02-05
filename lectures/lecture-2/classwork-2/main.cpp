#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    // 1
    int x = 2796;
    cout << hex << x << endl;
    
    // 2
    x = 0xF0A;
    cout << dec << x << endl;

    // 3
    string s1 = "how are you";
    string s2 = " doing well";
    cout << (s1 + s2) << endl;

    // 4
    int y = 7;
    cout << (y << 3) << endl;

    // 5
    int z = 200;
    cout << (z >> 3) << endl;

    // 6
    cout << right
        << setw(4) << "Plus"
        << setw(4) << "1"
        << setw(4) << "2"
        << setw(4) << "3"
        << setw(4) << "4"
        << setw(4) << "5"
        << endl;
    for (int i = 1;i <= 5;i++) {
        cout << right
            << setw(4) << i
            << setw(4) << i+1
            << setw(4) << i+2
            << setw(4) << i+3
            << setw(4) << i+4
            << setw(4) << i+5
            << endl;
    }

}


