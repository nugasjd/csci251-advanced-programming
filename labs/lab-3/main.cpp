#include <iostream>
#include <fstream>
#include <string>
#include <memory>
using namespace std;

string concatenateStrings(string arr[], int size) {
    string wholeStr;
    for (int i = 0; i < size; i++) {
        wholeStr += arr[i];
    }
    return wholeStr;
}

int main()
{
    cout << "************** Program 1 **************" << endl;
    // using delete[]
    int k;
    cout << "enter k: " << endl;
    cin >> k;
    for (int i = 1; i < k; i++)
    {
        int* ptr = new int[1000000];
        delete[] ptr;   
    }  //one million integers  4 Megabytes each iteration 
    cout << " OK allocated: " << (k * 4) << " Mega Bytes" << endl;
    
    // using smart pointer
    for (int i = 1;i <= k;i++) {
        long long sum = 0;
        unique_ptr<int[]> ptr(new int[1000]);  // allocates local 4 Mbyte memory inside a for statement
        for (int j = 0; j < 999; j++) {
            ptr[i] = 2;
            sum = sum + ptr[i];
        }
        // cout << sum << endl;
        ptr.release();  // releases the ownership of the stored pointer without destroying it
        ptr.reset();    // deletes object managed by the unique_ptr
    }

    cout << "************** Program 2 **************" << endl;
    string arr[] = { "great", "super", "done", "excellent"};
    cout << concatenateStrings(arr, 4) << endl;

    string arr2[] = { "great", "super", "done" };
    int size = sizeof(arr2) / sizeof(*arr2);
    cout << concatenateStrings(arr2, size) << endl;

    cout << "************** Program 3 **************" << endl;
    ifstream in("coding.txt");
    if (!in) {
        cout << "Cannot open text file" << endl;
        system("pause");
        return 1;
    }
    
    string singleStr;
    getline(in, singleStr, '\0');
    cout << singleStr << endl;
    
    // b, c and d
    in.seekg(0);
    string myLine;
    int count = 0;
    int iscount = 0;
    while (getline(in, myLine, '\n')) {
        // b counting num of lines
        count++;
        // c counting num of string 'is'
        // cout << "Index of string 'is' = " << myLine.find("is") << endl;
        if (myLine.find("is") <= myLine.size()) {
            iscount++;
        }
    }
    cout << "Number of lines in the text file = " << count << endl;
    cout << "Num of string 'is' = " << iscount << endl;

    ifstream inf("coding.txt");
    if (!inf) {
        cout << "Cannot open text file" << endl;
        system("pause");
        return 1;
    }
    cout << "\nReplace the string 'is' with 'is THE is':" << endl;
    while (getline(inf, myLine, '\n')) {
        if (myLine.find("is") <= myLine.size()) {
            int ipos = myLine.find("is");
            myLine.replace(ipos, 2, "is THE is");
        }
        cout << myLine << endl;
    }

}
