#include <iostream>
#include <iomanip>
using namespace std;

void swap(int & x, int & y) { // call by reference using & - allows access to x and y memory
    int temp = x;
    x = y;
    y = temp;
}

int main()
{
    int x = 7;
    int y = -20;
    swap(x, y);
    cout << "x = " << x << "   y = =" << y << endl;
    system("pause");

    int A[10][10];
    for (int i = 1;i <= 10;i++) {
        for (int j = 1;j <= 10;j++) {
            A[i - 1][j - 1] = i + j;
            cout << setw(4) << right << A[i - 1][j - 1] << " ";
        }
        cout << "\n";
    }
    system("pause");

    int xx = 198;
    cout << hex << xx << endl;
    system("pause");

    // converting hex to dec
    int yy = 0xF2A;
    cout << dec << yy << endl;


}

