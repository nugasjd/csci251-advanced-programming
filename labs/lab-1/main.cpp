#include <iostream>
#include <iomanip>
using namespace std;

// console output - cout

int main() {
	// P2
	cout << "********** Program 2 **********" << endl;
	int first = 9 / 2;	// division by integer
	double second = 9 / 2;
	cout << "1st = " << first << endl;
	cout << "2nd = " << second << endl;

	// if double is used the value shown will be a double
	// val is truncated to 4 since the var is int
	first = 9 / 2.00;	
	second = 9 / 2.00;
	cout << "1st = " << first << endl;
	cout << "2nd = " << second << endl;

	// P3
	cout << "********** Program 3 **********" << endl;
	int num1;
	int num2;
	cout << "Enter 1st number: ";
	cin >> num1;
	cout << "Enter 2nd number: ";
	cin >> num2;
	int ans = num1 + num2;
	cout << "Ans = " << ans << endl;

	// P4
	// sizeof(arr) = num of elem * sizeof(each elem) <-- dont use sizeof for size of arr
	cout << "********** Program 4 **********" << endl;
	double arr[] = { 7.5, 3.3, 2.5, 8.7, 9.6 };
	const int NUMBER_OF_ARRAY_ELEMENTS = 5;	// use constant for size of arr
	cout << "Before switching: ";
	for (int i = 0; i < NUMBER_OF_ARRAY_ELEMENTS; i++) {
		cout << arr[i] << " ";
	}

	// switching 1st and last elem
	double temp = arr[0];
	arr[0] = arr[4];
	arr[4] = temp;

	cout << "\nAfter switching: ";
	for (int i = 0; i < NUMBER_OF_ARRAY_ELEMENTS; i++) {
		cout << arr[i] << " ";
	}

	// P5
	cout << "\n********** Program 5 **********" << endl;
	string str = "Hello C++ World.";
	bool found = false;
	for (int i = 0; i <= str.length(); i++) {
		if (str[i] == 'C') {
			found = true;
			break;
		}
	}
	if (found) cout << "C Found" << endl;
	else cout << "C Not Found" << endl;

	// P6
	/*
	 reference variable --> &
	 both mydouble and myreference point to the same value
	 so if there are any changes made it will affect both of them
	 can access files using pointers
	*/
	cout << "********** Program 6 **********" << endl;
	double mydouble = 9.0;
	double& myreference = mydouble;
	cout << mydouble << " " << myreference << endl;
	myreference = 8.5;
	cout << mydouble << " " << myreference << endl;
	mydouble = 3.45;
	cout << mydouble << " " << myreference << endl;
	
	// P7
	cout << "********** Program 7 **********" << endl;
	char ch;
	int intNum;
	double doubleNum;
	cout << "Enter a character: ";
	cin >> ch;
	cout << "Enter an integer: ";
	cin >> intNum;
	cout << "Enter a double: ";
	cin >> doubleNum;
	cout << "Char=" << ch << "; Integer=" << intNum << "; Double=" << doubleNum << endl;
	

	// P8
	// without formatting
	cout << "********** Program 8 **********" << endl;
	cout << "Without string formatting:" << endl;
	cout << "N    N^2    N^3" << endl;
	for (int i = 1; i <= 10;i++) {
		cout << i << "    " << pow(i, 2) << "    " << pow(i, 3) << endl;
	}

	// with string formatting
	cout << "With string formatting:" << endl;
	cout << right 
		<< setw(3) << "N"
		<< setw(5) << "N^2"
		<< setw(5) << "N^3" << endl;
	for (int i = 1; i <= 10;i++) {
		cout << right
			<< setw(3) << i
			<< setw(5) << pow(i, 2)
			<< setw(5) << pow(i, 3)
			<< endl;
	}

	// P9
	cout << "********** Program 9 **********" << endl;
	int arr2[] = { 1,2,3,4,5,6,7,25,9,10,11,12,13,32 };
	const int NUM_OF_ARRAY_ELEMENTS = 14;
	cout << "Without string formatting: " << endl;
	cout << "N    N^2    N^3" << endl;
	for (int i = 0; i < NUM_OF_ARRAY_ELEMENTS;i++) {
		cout << arr2[i] << "    " << pow(arr2[i], 2) << "    " << pow(arr2[i], 3) << endl;
	}

	cout << "With string formatting: " << endl;
	cout << right
		<< setw(3) << "N"
		<< setw(10) << "N^2"
		<< setw(10) << "N^3" << endl;
	for (int i = 1; i < NUM_OF_ARRAY_ELEMENTS;i++) {
		cout << right
			<< setw(3) << arr2[i]
			<< setw(10) << pow(arr2[i], 2)
			<< setw(10) << pow(arr2[i], 3)
			<< endl;
	}
	cout << "*******************************" << endl;


	return 0;
}
