#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    cout << "************** Program 1 and 2a **************" << endl;
    // 2
    struct record {
        int id = 0;
        string name = "***";
        int test1 = 0;
        int test2 = 0;
        int test3 = 0;
        double average = 0;
    };
    record list[40];

    // 1
    ifstream in("students_in.txt");
    ofstream out("students_out.txt");
    if (!in) {
        cout << "Cannot open text file" << endl;
    }
    string line, id, name, test1, test2, test3;

    int counter = 0;

    getline(in, line, '\n');
    out << "id          Name        avg" << endl;
    while (getline(in, id, ':')) {
        getline(in, name, ':');     
        getline(in, test1, ':');
        getline(in, test2, ':');
        getline(in, test3, ':');
        // remove whitespace
        remove(name.begin(), name.end(), ' ');
        remove(test1.begin(), test1.end(), ' ');
        remove(test2.begin(), test2.end(), ' ');
        remove(test3.begin(), test3.end(), ' ');

        // 2
        list[counter].id = stoi(id);
        list[counter].name = name;
        list[counter].test1 = stoi(test1);
        list[counter].test2 = stoi(test2);
        list[counter].test3 = stoi(test3);
        list[counter].average = (stoi(test1) + stoi(test2) + stoi(test3)) / 2.;
        counter++;
        
    }

    for (int i = 0;i < counter;i++) {
        cout << list[i].id << " " << list[i].name << " " << list[i].test1 << " " << list[i].test2 << " " << list[i].test3 << " " << list[i].average << endl;
    }

    // saved to "students_out.txt"
    for (int i = 0;i < counter;i++) {
        out << list[i].id << " " << list[i].name << " " << list[i].test1 << " " << list[i].test2 << " " << list[i].test3 << " " << list[i].average << endl;
    }

    in.close();
    out.close();

    
    cout << "\n************** Program 2b **************" << endl;
    cout << " Binary file" << endl;
    ofstream outb("students.bin", ios::binary);
    for (int i = 0;i < counter;i++) {
        outb.write((char*)&list[i], sizeof(record));
    }
    outb.close();
    
    cout << "\n************** Program 3 **************" << endl;
    ifstream inb("students.bin", ios::binary);
    if (!inb) {
        cout << "Cannot open binary file" << endl;
        system("pause");
    }

    inb.seekg(0);
    record rec;
    for (int k = 0;k < counter;k++) {
        inb.read((char*)&rec, sizeof(record));
        cout << rec.id << " " << rec.name << " " << rec.test1 << " " << rec.test2 << " " << rec.test3 << " " << rec.average << endl;
    }

    cout << "\n5th record: " << endl;
    inb.seekg((4) * sizeof(record));
    inb.read((char*)&rec, sizeof(record));
    cout << rec.id << " " << rec.name << " " << rec.test1 << " " << rec.test2 << " " << rec.test3 << " " << rec.average << endl;
    cout << "1st record: " << endl;
    inb.seekg((0) * sizeof(record));
    inb.read((char*)&rec, sizeof(record));
    cout << rec.id << " " << rec.name << " " << rec.test1 << " " << rec.test2 << " " << rec.test3 << " " << rec.average << endl;
    cout << "3rd record: " << endl;
    inb.seekg((2) * sizeof(record));
    inb.read((char*)&rec, sizeof(record));
    cout << rec.id << " " << rec.name << " " << rec.test1 << " " << rec.test2 << " " << rec.test3 << " " << rec.average << endl;
    
    inb.seekg(0);
    while (true) {
        cout << "Which record do you want to display? " << endl;
        int irec;
        cin >> irec;
        if ((irec < 1) || (irec > 5)) break;
        inb.seekg((irec - 1) * sizeof(record));
        inb.read((char*)&rec, sizeof(record));
        cout << rec.id << " " << rec.name << " " << rec.test1 << " " << rec.test2 << " " << rec.test3 << " " << rec.average << endl;
    }

    inb.close();
    
    cout << "\n************** Program 5 **************" << endl;
    string str("This is a string");
    for (char c : str) cout << c << endl;
    
    int arr[] = { 3,7,9 };
    for (auto i : arr) cout << i << endl;

    system("pause");
}
