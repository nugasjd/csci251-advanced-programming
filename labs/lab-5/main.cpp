#include <iostream>
#include <string>
#include <cmath>
#define M_PI 3.14159265358979323846
#include <iostream>
using namespace std;

/* Difference between struct and class:
struct is cheaper/simpler ver of class
pretty much the same. both are advanced data type
no privacy, its all public. can access levels of certain things
e.x. can embed and implement linked list in struct 
*/

// 1
enum typeP { villa, townhouse, apartment };
struct property {
    // enum typeP { villa, townhouse, apartment }; 
    /*^ can declare outside class cuz were gnna use it in main
    if used inside the struct, use property::typeP::villa.. in the main
    */
    typeP type;
    int noOfRooms;
    int noOfBathrooms;
    int noOfGarage;
    double sellingPrice;

    // instance called when struct/class is created
    // assigns variables. special method
    property(typeP t, int r, int b, int g, int p) {
        type = t;
        noOfRooms = r;
        noOfBathrooms = b;
        noOfGarage = g;
        sellingPrice = p;
    } // parameter constructor

    void display() {
        cout << "Property type: " << type << endl;
        cout << "Number of rooms: " << noOfRooms << endl;
        cout << "Number of bathrooms: " << noOfBathrooms << endl;
        cout << "Number of garages: " << noOfGarage << endl;
        cout << "Selling price in AED: " << sellingPrice << endl;
    }
};

// 3
template <class T>
double circleArea(T &radius) {
    const double pi = M_PI;
    T area = pi * pow(radius, 2);
    return area;
}

// 4
template <class T>
void displayNum(T &n) {
    cout << n << endl;
}
// class and functions

int main()
{
    // 1
    cout << "************** Program 1 **************" << endl;
    property p1(villa, 7, 4, 2, 4567);
    property p2(townhouse, 5, 3, 1, 3678);
    property p3(apartment, 3, 2, 0, 2234);
    property arr[] = {p1, p2, p3};

    for (auto elem : arr) {
        elem.display();
        cout << endl;
    }

    // 3
    cout << "\n************** Program 3 **************" << endl;
    int r = 12;
    double area = circleArea(r);
    cout << "Area of circle (using int) = " << area << endl;
    double r2 = 8.9;
    area = circleArea(r2);
    cout << "Area of circle (using double) = " << area << endl;
    
    // 4
    cout << "\n************** Program 4 **************" << endl;
    int i = 9;
    char c = 's';
    string s = "a string";
    displayNum(i);
    displayNum(c);
    displayNum(s);   
}
