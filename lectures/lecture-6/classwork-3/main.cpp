#include <iostream>
#include <string>
using namespace std;

class Transaction {
private:
    int id;
    double amount;
public:
    Transaction() { id = 0; amount = 0; }    // default contructor 
    Transaction(int id, double amount): id(id), amount(amount) {}    // parametized constructor

    // friend function to display transaction
    friend void display(Transaction t);

    // overload + operator to add to Transaction objects
    Transaction operator +(Transaction t2) {
        Transaction temp;
        temp.id = this->id + t2.id;    // keep current id
        temp.amount = this->amount + t2.amount;    // sum amounts
        return temp;
    }

    // overload + operator to add int to Transaction amount
    Transaction operator +(int i) {
        Transaction temp;
        temp.id = this->id;
        temp.amount = this->amount + i;
        return temp;
    }

    // friend function to add Transaction and int (int + Transaction)
    friend Transaction operator +(int i, Transaction t) {
        Transaction temp;
        temp.id = t.id;
        temp.amount = i + t.amount;
        return temp;
    }

    // overload << operator to print Transaction
    friend ostream& operator <<(ostream& out, Transaction t) {
        cout << t.id << "   " << t.amount << endl;
        return out;
    }
};

// display Transaction using a func
void display(Transaction t) {
    cout << "id=" << t.id << ", amount=" << t.amount << endl;
}


int main()
{
    Transaction t1(897, 980.8);
    Transaction t2(342, 3000);
    Transaction t3 = t1 + t2;   // should have same id as t1 and the amount is the sum of the 2 amounts
    cout << t1 << endl;
    t1 = t1 + 299;
    display(t1);
    t1 = 389 + t1;
    display(t1);

    system("pause");
}


