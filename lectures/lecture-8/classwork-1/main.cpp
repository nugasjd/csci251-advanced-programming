#include <iostream>
using namespace std;

template <class T>
class Transaction {
    int id;
    T balance;
public:
    Transaction(int id, T balance): id(id), balance(balance) {}
    friend ostream& operator <<(ostream& o, Transaction t) {
        o << t.id << ": " << t.balance << endl;
        return o;
    }
    T operator +(int num) {
        return (t.balance + num);
    }
    friend T operator +(int num, Transaction t) {
        return (num + t.balance);
    }
};

int main()
{
    Transaction<double> t1(7797412, 4578.3);
    Transaction<long> t2(7234786, 9999909739);
    
    cout << t1 <<endl;
    double t;
    t = t1 + 50;
    cout << "t = " << t << endl;
    t = 50 + t1;
    cout << "t = " << t << endl;

    cout << t2 << endl;
    t = t2 + 50;
    cout << "t = " << t << endl;
    t = 50 + t2;
    cout << "t = " << t << endl;
}


