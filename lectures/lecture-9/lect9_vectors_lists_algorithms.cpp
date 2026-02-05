#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Pair {
public:
    Pair() { int x = 0; int y = 0; cout << "Default constructor" << endl; }
    Pair(int i, int j) { x = i; y = j; cout << "Parameter constructor called" << endl; }
    Pair(Pair & p) { x = p.x; y = p.y; cout << "Copy constructor called" << endl; }
private:
    int x, y;
};

void f1(Pair p) {
    cout << "f1 is called" << endl;
}

// func to reverse a vector of chars
vector <char> Myreverse(vector <char> v) {
    vector <char> temp;
    if (v.size() == 0) return temp;
    vector <char>::iterator iter = v.end() - 1;
    
    for (; iter != v.begin()-1; iter--) {
        temp.push_back(*iter);
    }
    temp.push_back(*v. begin());
    return temp;
}

int main()
{
    Pair p1(3, -4); // parameterized
    Pair p2;        // default
    Pair p3(p1);    // copy
    f1(p1);         // pass by value 

    vector <string> vs1;
    vs1.push_back("Abdul");
    vs1.push_back("Afwan");
    vs1.push_back("Drisian");

    // copy vector using copy constructor
    cout << "vs2(vs1): " << endl;   
    vector<string> vs2(vs1);
    for (auto elem : vs2) cout << elem << "  ";
    cout << endl;

    // iterating using iterator
    cout << "Displaying using iterators:" << endl;
    vector<string>::iterator iter = vs1.begin();
    for (; iter != vs1.end(); iter++) {
        cout << *iter << "  ";
    }
    cout << endl;

    // insert elements at beginning and end
    vs1.insert(vs1.begin(), "omar");
    vs1.insert(vs1.end(), "Saad");
    for (auto elem : vs1) cout << elem << "  ";
    cout << endl;

    // to erase last item in array/list => erase.end()-1
    cout << "Erasing elements: " << endl;
    vs1.erase(vs1.begin());
    vs1.erase(vs1.end()-1);
    for (auto elem : vs1) cout << elem << "  ";
    cout << endl;

    // erasing a sequence of elements/multiple elem
    string arr[] = { "Hamid", "Samer", "Mounia" };
    copy(arr, arr + 3, back_inserter(vs1));   // copies arr into vs1
    for (auto elem : vs1) cout << elem << "  ";
    cout << endl;

    // erasing items from index 1 to 3
    iter = vs1.begin();
    vs1.erase(iter + 1, iter + 4);  // iter+4 <= 2nd parameter should be taken after the elem u want to delete
    for (auto elem : vs1) cout << elem << "  ";
    cout << endl;

    char arr2[] = { 'A', 'B', 'C', 'D' };
    vector <char> vc;
    copy(arr2, arr2 + 4, back_inserter(vc));
    for (auto elem : vc) cout << elem << "  ";
    cout << endl;
    
    // testing empty vector reversal
    cout << "Testing empty vectors" << endl;
    vector<char> vc2 = Myreverse(vc2);
    for (auto elem : vc2) cout << elem << "  ";
    cout << endl;

    // learning lists
    list<char> list1;
    list1.push_back('E');
    list1.push_back('J');
    for (auto elem : list1) cout << elem << "  ";
    cout << endl;

    // adding more elements and reversing
    cout << "After reverse" << endl;
    copy(arr2, arr2+4, back_inserter(list1));
    list1.reverse();
    for (auto elem : list1) cout << elem << "  ";
    cout << endl;

    // sorting
    cout << "After sorting" << endl;
    list1.sort();
    for (auto elem : list1) cout << elem << "  ";
    cout << endl;

    // using unique - removes duplicated values
    cout << "Adding a duplicate value" << endl;
    list1.push_back('B');
    for (auto elem : list1) cout << elem << "  ";
    cout << endl;
    cout << "Using unique to remove duplicate value";
    list1.sort();
    list1.unique();
    for (auto elem : list1) cout << elem << "  ";
    cout << endl;

    system("pause");
}


