#include <iostream>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

// Student class to store ID and name
class Student {
	const int id;	// const - cannot be changed after initialization
	string name;
public:
	Student(int id, string name):id(id) {
		// semantic error: if const int id, then u cant use this->id=id because its not allowed to change
		// instead use :id(id) for const
		this->name = name;
	}
	void set(int id2, string name) {
		// this->id = id;
		this->name = name;
	}
	// should be friend because you are passing Student s, operator should have access to Student s
	// friend can access public and private vars of Student s 
	friend ostream& operator <<(ostream& o, Student s) {	// use o not cout for parameter
		o << s.id << "   " << s.name << endl;
		return o;
	}
};

// pair class
template <class T>
class Pair {	
	T x, y;	// use T instead of a specific data type
public:
	Pair(T& xx, T& yy) {
		cout << xx << yy << endl;
	}
};

// swap function
template <class T>
void MySwap(T &a, T &b) {
	T temp = b;
	b = a;
	a = temp;
}

int main()
{
	// 1 Simple string encryption/decryption
	string plain = "Do not tell secret message";
	char key = 'z';
	
	// encrypting
	string encrypt = "";
	for (auto ch : plain) {	
		encrypt += (ch ^ key);	// XOR each character with key
	}
	cout << encrypt << endl;

	// decrypting
	string plain2 = "";
	for (auto ch : encrypt) {
		plain2 += (ch ^ key);	// XOR again with same key to get original text
	}
	cout << plain2 << endl;

	// 2 File-based encryption
	ifstream in("notes.txt"); 	// open input file containing plain text
	ofstream out("notes.enc");	// output file for encrypted text
	if (!in) {	// to check if input file opened successfully
		cout << "Cannot open text file" << endl;
		system("pause");
	}
	
	string plainText;
	getline(in, plainText, '\0');	// read entire content of the file

	// encrypting plain text
	char key2 = 'a';
	string enc = "";
	for (auto ch : plainText) {
		enc += (ch ^ key2);
	}

	out << enc << endl;		// saving encrypted text to notes.enc

	// close input and output file
	in.close();	
	out.close();

	// 3 Student class examples
	// must initialize each object
	Student s1(4567, "Afwan");
	Student s2(8965, "Ahmed");
	cout << s1 << endl;		// the left is not Student, its cout (reference to type ostream)
	cout << "hello" << s1 << "bye" << endl;

	// 4 Generic pair class examples
	Pair<int> p1(45, 35); // generic class -> Pair p1(45, 35);
	Pair<string> p2("hi", "bye");
	Pair<Student> p3(s1, s2);
	
	// 5 Swapping 2 strings
	string a = "one";
	string b = "two";
	MySwap(a, b);
	cout << "a=" << a << "  b=" << b << endl;
	cout << "Thanks\n";
}

