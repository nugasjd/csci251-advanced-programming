#include <iostream>
#include <iomanip>
using namespace std;

class Staff {
    int staffno;
    string lastName;
    string firstName;
    double baseSalary;
    double salesMade;
    const static string Sales[3];
    const static double ClassA[3];
    const static double ClassB[3];
    const static double ClassC[3];
public:
    Staff(int staffno, string lastName, string firstName, double baseSalary, double salesMade) {
        this->staffno = staffno;
        this->lastName = lastName;
        this->firstName = firstName;
        this->baseSalary = baseSalary;
        this->salesMade = salesMade;
        string Sales[3] = {"0-20", "21-50", "51+"};
        double ClassA[3] = { 0.03, 0.05, 0.075 };
        double ClassB[3] = { 0.02, 0.035, 0.055 };
        double ClassC[3] = { 0.005, 0.015, 0.04 };
    }

    friend static void displayTable(Staff s);

    double computeBonus() {
        double bonus = 0;
        string staffClass;
        cout << "Enter staff class: " << endl;
        cin >> staffClass;
        if (salesMade >= 0 && salesMade <= 20) {
            if (staffClass == "A") bonus = salesMade * (1 + ClassA[0]);
            else if (staffClass == "B") bonus = salesMade * (1 + ClassB[1]);
            else if (staffClass == "C") bonus = salesMade * (1 + ClassC[2]);
        }
        else if (salesMade >= 21 && salesMade <= 50) {
            if (staffClass == "A") bonus = salesMade * (1 + ClassA[0]);
            else if (staffClass == "B") bonus = salesMade * (1 + ClassB[1]);
            else if (staffClass == "C") bonus = salesMade * (1 + ClassC[2]);
        }
        else if (salesMade > 50) {
            if (staffClass == "A") bonus = salesMade * (1 + ClassA[0]);
            else if (staffClass == "B") bonus = salesMade * (1 + ClassB[1]);
            else if (staffClass == "C") bonus = salesMade * (1 + ClassC[2]);
        }
    }

    void display() {
        cout << right
            << setw(7) << staffno 
            << setw(15) << firstName 
            << setw(15) << lastName 
            << setw(7) << baseSalary 
            << setw(7) << salesMade << endl;
    }
};

static void displayTable(Staff s) {
    for (int i = 0;i < s.Sales->length();i++) {
        cout << left
            << setw(6) << s.Sales[i]
            << setw(6) << s.ClassA[i]
            << setw(6) << s.ClassB[i]
            << setw(6) << s.ClassC[i] << endl;
    }
}

template <class T>
void display2D(T arr[][2], int nRows) {
    for (int i = 0;i < nRows;i++) {
        for (int j = 0;j < 2;j++) {
            cout << right
                << setw(5) << arr[i][j] << "  ";
        }
        cout << endl;
    }
}

int main()
{
    Staff s1(7797412, "Nugas", "Jewel", 6789, 354);
    Staff s2(9745692, "Bang", "Chris", 3567, 678);
    Staff s3(2356409, "Red", "Berry", 5678, 245);
    cout << "Diplaying bonus table: " << endl;
    displayTable(s1);
    s1.display();
    s2.display();
    s3.display();

    // 2
    cout << "************** Program 3 **************" << endl;
    int array[3][2] = { {6, 7}, {4, 9}, {-2, -12} };
    display2D(array, 3);
    long array2[3][2] = { {9887634452, 2988979843}, {9287943474, 29384793456}, {7892307583, 89345793467} };
    string array3[2][2] = { {"one", "two"}, {"three", "four"} };
    display2D(array3, 2);
    Staff array4[1][2] = { s1, s2 };

}
