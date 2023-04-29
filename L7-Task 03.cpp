// Task 03.cpp : This file is a solution to a problem in Lab 07
//

#include <iostream>
using namespace std;
static int id = 0;
class animal {
protected:
    string name;int age, Id;
public:
    animal() {
        Id = id;
        id++;
    }
};
class lion : virtual public animal{
protected:
    int teeth;
public:
    void getData(string x, int y, int z) {
        name = x, age = y, teeth = z;
    }
    void printData() {
        cout << "\nLion Data:\n";
        cout << "Name: " << name << "\nAge: " << age << "\nTeeth: " << teeth;
    }
    lion() {
        Id = id;
        id++;
    }
};
class eagle: virtual public animal {
protected:
    int head, wings;
public:
    eagle() {
        Id = id;
        id++;
    }
    void getData(string x, int y, int z, int a) {
        name = x, age = y, head = z, wings = a;
    }
    void printData() {
        cout << "\nEagle Data:\n";
        cout << "Name: " << name << "\nAge: " << age << "\nHead: " << head << "\nWings: " << wings << endl;
    }
};
class griffin : public lion, public eagle{
public:
    griffin() {
        Id = id;
        id++;
    }
};
int main()
{
    cout << "Lab 07\n";
    animal a;
    lion l;
    eagle e;
    griffin g;
}