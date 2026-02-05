#include <iostream>
#include <vector>
using namespace std;

vector <int> addaNumber(vector<int> v, int n) {
    vector<int> temp;
    vector <int>::iterator iter = v.begin();

    for (; iter != v.end(); iter++) {
        temp.push_back((*iter) + n);
    }
    return temp;
}

int main()
{
    vector <int> vi1;
    vi1.push_back(23);
    vi1.push_back(6);
    vi1.push_back(18);
    
    cout << "Displaying vector: " << endl;
    vector<int>::iterator iter = vi1.begin();
    for (; iter != vi1.end(); iter++) {
        cout << *iter << "  ";
    }

    cout << "\nVector after adding a number: " << endl;
    vector<int> vin = addaNumber(vi1, 3);
    for (auto elem : vin) cout << elem << endl;
}


