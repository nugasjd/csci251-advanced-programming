#include <iostream>
#include <map>
#include <vector>
#include <algorithm>    // used for for_each
using namespace std;

vector <int>incrementByN(vector<int> v, int N) {
    vector<int>::iterator iter;
    for (iter = v.begin(); iter != v.end();iter++) {
        (*iter) = (*iter)+N;
    }
    return v;
}

int do1(int elem) {
    cout << "In do1 " << elem << endl;
    return elem + 10;
}

int do2() {
    static int data = 5;    // declaring a static in a function
    data = data + 3;
    return data;
}   // output: 8, 11, 14, etc..
// if without static, data will always return 8

int main()
{
    map<char, string, less<char>> m1;    // greater/less
    // populating map
    m1['h'] = "Halim";  // h=key, Halim=value
    m1['d'] = "Dream";
    m1['k'] = "Tchan";
    m1['k'] = "Mahad";  // there can only be unique keys, Mahad will be shown not Tchan (override)
    m1['a'] = "Soly";
    m1['A'] = "Soly";

    // display: iterators/auto
    // first & second are attributes
    cout << "Displaying map using auto:" << endl;
    for (auto elem : m1) {
        cout << elem.first << "  " << elem.second << endl;
    }

    cout << "Displaying map using iterators:" << endl;
    map<char, string, less<char>>::iterator iter;    // declaring iterator
    for (iter = m1.begin(); iter != m1.end();iter++) {   // iter!= <- stopping condition
        cout << (*iter).first << "  " << (*iter).second << endl;
    }

    // erasing elem in map
    m1.erase(m1.begin());   // erases according to the sorted map
    cout << "After erase:" << endl;
    for (auto elem : m1) {
        cout << elem.first << "  " << elem.second << endl;
    }

    iter = m1.begin();
    advance(iter, m1.size() - 1);
    m1.erase(iter); // erases last item

    /* cant do these:
    m1.erase(m1.end()-1);
    iter=iter+5;
    */

    // erasing by key
    cout << "Finding value using key:" << endl;
    iter = m1.find('k');
    { if (iter != m1.end()) cout << (*iter).second << endl; // 
    m1.erase(iter); }

    // algorithm
    int arr[] = { 9, -8, 12, 7, 9, 5, -9 };
    vector<int> v1;
    copy(arr, arr + 7, back_inserter(v1));  // copying arr into v1
    for (auto elem : v1) { cout << elem << "  "; }
    cout << endl;
    v1.insert(v1.begin(), 80);  
    v1.insert(v1.end(), 79);    
    v1.erase(v1.begin());
    v1.erase(v1.end() - 1);

    cout << "Adding a constant to each element" << endl;
    v1 = incrementByN(v1, 7);
    for (auto elem : v1) { cout << elem << "  "; }
    cout << endl;

    for_each(v1.begin(), v1.end(), do1);    // do1 - receives iterator

    for (int k = 1;k <= 3;k++) {
        int value = do2();
        cout << "Value = " << value << endl;
    }
}
