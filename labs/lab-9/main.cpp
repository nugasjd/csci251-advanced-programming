#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
#include <map>
#include <list>
using namespace std;

vector<int> gen() {
    vector<int> v2;
    for (int i = 3;i <= 21;i=i+3) {
        v2.push_back(i);
    }
    return (v2);
}

int main()
{
    cout << " ***************************** Program 1 *****************************" << endl;
    vector<int> v;
    v.push_back(5);  v.push_back(6); v.push_back(5);
    v.push_back(16); v.push_back(-12); v.push_back(9);
    v.push_back(5);  v.push_back(6); v.push_back(5);v.push_back(5);
    // will be inserted at the back of the array

    // a) display the vector using iterator and auto
    vector <int>::iterator iter = v.begin();    // iter - used as ptr 
    for (; iter != v.end(); iter++) {
        cout << *iter << "  ";
    }
    cout << endl;
    
    for (auto elem: v) {
        cout << elem << "  ";
    }
    cout << endl;
    
    // b) display the vector using algorithm copy and ostream_iterator template function
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, "  "));

    cout << " ***************************** Program 2 *****************************" << endl;
    ostream_iterator<int> cout_it(cout, " ");
    vector<int> v2(7);  // create a vector with seven elements
    cout << v2.size() << endl;

    generate(v2.begin(), v2.end(), gen);

    // display the generated vector using auto
    for (auto elem : v2) {
        cout << elem << "  ";
    }
    cout << endl;
    
    // an arr can be copied into another array of a bigger size

    cout << " ***************************** Program 3 *****************************" << endl;
    map<int, list<string>, less<int>> m;
    m[5].push_back("cat");   // the key 5  is for lists of animals
    m[5].push_back("horse");
    m[5].push_back("rabbit");

    m[1].push_back("orange");  // the key 1 is for fruits
    m[1].push_back("apple");   // the key 1 is for fruits
    m[1].push_back("mango");   // the key 1 is for fruits

    m[3].push_back("Pakistan");  // the key 3 if countries
    m[3].push_back("Egypt");
    m[3].push_back("India");
    m[3].push_back("UAE");
    m[3].push_back("Malta");

    // 1. write code to display all the map
    cout << "Using auto to display map:" << endl;
    for (const auto& pair: m) {
        cout << "Key: " << pair.first << endl;
        cout << "Values: " << endl;
        for (const auto& value : pair.second) {
            cout << "- " << value << endl;
        }
        cout << endl;
    }

    m[3].pop_back();
    m[1].sort();
    reverse(m[2].begin(), m[2].end()); 
    m.erase(m.begin());

    /* 2. write the code to display the map    
     what do you expect would be the output?
     Rewrite 1 and 2 as a function so that you do not type the code twice 
     mydisplay(m); */

    m.insert(make_pair(6, list251));           // list 251 is a list of some of your friends   
}
