// Task 04.cpp : This file is a solution to a problem in Lab 07.
//

#include <iostream>
using namespace std;
class player {
protected:
    string name;
    int age;
    float amount;
};
class batsman : virtual public player {
protected:
    string role;
};
class bowler : virtual public player {
protected:
    string type;
};
class allRounder: public batsman, public bowler {
public:
    allRounder(string w, int x, float y, string z, string a) {
        name = w, age = x, amount = y, role = z, type = a;
    }
    void display() {
        cout << "Player Role: " << role << "\nName: " << name << "\nAge: " << age << "\nAmount: " << amount << "\nType of Bowling: " 
             << type << endl;
    }
};
int main()
{
    string name, role, type;
    float amount; int age;
    cout << "Task 04\n";
    cout << "Enter player Name, age, amount, role and type:" << endl;
    cin >> name >> age >> amount >> role >> type;
    allRounder r(name, age, amount, role, type);
    r.display();
}
