#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    struct record {
        int id = 000;
        string name = "****";
        int test1 = 0;
        int test2 = 0;
        double avg = 0;
    };
    
    ifstream in ("students.txt");   // open file
    if (!in) {  // file doesnt exist or path is wrong
        cout << "Cannot open text file" << endl;
        system("pause");
        return 1;
    }

    // read file
    string line, sid, sname, stest1, stest2;
    record list[100];
    int counter = 0;

    getline(in, line, '\n');    // skip the first line (ID Name test1 test2)
    while (getline(in, sid, ':')) {
        getline(in, sname, ':');
        getline(in, stest1, ':');
        getline(in, stest2, '\n');
        cout << sid << " " << sname << " " << stest1 << " " << stest2 << endl;
        list[counter].id = stoi(sid);
        // strcpy_s(list[counter].name, sname.c_str());
        // list[counter].name = sname;   <-- replace w above line of code
        list[counter].test1 = stoi(stest1);
        list[counter].test2 = stoi(stest2);
        list[counter].avg = (stoi(stest1) + stoi(stest2)) / 2.;
        counter++;
    }

    cout << "All students record are there" << endl;
    for (int i = 0;i < counter;i++) {
        cout << list[i].id << " " << list[i].name << " " << list[i].test1 << " " << list[i].test2 << " " << list[i].avg << endl;
    }
    in.close();

    ofstream out("students_output.txt");
    out << line << "    Avg" << endl;
    for (int i = 0;i < counter;i++) {
        out << list[i].id << " " << list[i].name << " " << list[i].test1 << " " << list[i].test2 << " " << list[i].avg << endl;
    }
    out.close();

    // to a binary file
    cout << "Binary file" << endl;
    ofstream outb("students.bin", ios::binary);
    for (int i = 0;i < counter;i++) {
        outb.write((char*)&list[i], sizeof(record));
    }
    // outb.write((char*)&list[0], sizeof(record));
    outb.close();

    
    ifstream inb("students.bin", ios::binary);
    if (!inb) {  
        cout << "Cannot open binary file" << endl;
        system("pause");
        return 1;
    }

    cout << endl << "From the binary file" << endl;

    inb.seekg(0);   // it starts from beginning, used for writing
    record rec;
    for (int k = 0;k < counter;k++) {
        inb.read((char*)&rec, sizeof(record));
        cout << rec.id << " " << rec.name << " " << rec.test1 << " " << rec.test2 << " " << rec.avg << endl;
    }
    while (true) {
        cout << "Which record do you want to display? " << endl;
        int irec;
        cin >> irec;
        if ((irec < 1) || (irec > 5)) break;
        inb.seekg((irec-1) * sizeof(record));
        inb.read((char*)&rec, sizeof(record));
        cout << rec.id << " " << rec.name << " " << rec.test1 << " " << rec.test2 << " " << rec.avg << endl;
    }
    inb.close();

    /* simulating memory leak
    int iter;
    cout << "How many times do you want to look: " << endl;
    cin >> iter;
    for (int k = 0;k < iter;k++) {
        int* ptr = new int[1000000];
        delete [] ptr;
    }
    cout << "No memory leak" << endl;
    */

    // enhanced for statement
    string arr[] = { "great", "Umair", "Ahmed" };
    for (auto elem : arr) cout << elem << endl; // can put string or auto

    system("pause");
}


