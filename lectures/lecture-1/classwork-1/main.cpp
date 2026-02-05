#include <iostream>
using namespace std;

// class work 1
int main()
{
    // 1
    int x = 123;
    x += 20;
    cout << "x = " << x << endl;

    // 2
    double mydouble = 26;
    double* ptr = &mydouble;
    cout << "mydouble = " << *ptr << endl;
    
    // 7
    int a;
    cout << typeid(a).name() << endl;
    
    // 8.1
    /*
    * fam1 - 2 couples, 2 children
    * fam2 & fam3 - 2 couples, 1 child
    */
    double totCharge;
    const double tax = 9.5 / 100;
    cout << "Enter total charge (before tax): " << endl;
    cin >> totCharge;
    totCharge = totCharge + (totCharge * tax) + (totCharge * 0.2);
    cout << "Total charge (after tax and service) = " << totCharge << endl;
    
    double totPeople = 6 + (4 * 0.75);
    double indCharge = totCharge / totPeople;   // cost for each person
    double fam1 = (2 * indCharge) + (2 * (indCharge * 0.75));
    double fam2 = (2 * indCharge) + (indCharge * 0.75);
    double fam3 = (2 * indCharge) + (indCharge * 0.75);
    double totBill = fam1 + fam2 + fam3;
    cout << "Family 1 = " << fam1 << "\nFamily 2 = " << fam2 << "\nFamily 3 = " << fam3 << endl;
    cout << "Total Bill=" << totBill << endl;
    
    // 8.2
    double weeklyRate;
    int extraHrs;
    double totalPayment;
    cout << "Enter weekly rate: ";
    cin >> weeklyRate;
    cout << "Enter number of extra hours worked last week: ";
    cin >> extraHrs;
    
    const double hourlyRate = weeklyRate / 40;
    totalPayment = weeklyRate + (extraHrs * hourlyRate);
    cout << "Total payment = " << totalPayment << endl;

    // 8.3
    const double TV = 1400.00;
    const double DVD = 220.00;
    const double remote = 35.20;
    int numTV;
    int numDVD;
    int numRemote;

    cout << "Enter quantity of TV sets: ";
    cin >> numTV;
    cout << "Enter quantity of DVD players: ";
    cin >> numDVD;
    cout << "Enter quantity of remote controllers: ";
    cin >> numRemote;

    double subtotal = (TV * numTV) + (DVD * numDVD) + (remote * numRemote);
    double totalCost = subtotal + (subtotal * 8.25);
    cout << "Total cost = " << totalCost << endl;

}


