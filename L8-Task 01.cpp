// Task01.cpp : This file is a solution of Lab 08
//

#include <iostream>
using namespace std;
class bird {
private:
    string color, type, feather;
public:
    void setc() {
        color = "Grey";
        cout << "Bird color: " << color<<endl;
    }
    void setc(string color) {
        this->color = color;
        cout << "Bird color: " << color<<endl;
    }
    void move(string x) {
        cout << "The bird can " << x << endl;
    }
    void move() {
        cout << "The bird can only walk" << endl;
    }
};
int main()
{
    cout << "Task 01\n";
    bird b1, b2;
    b1.setc();
    b2.setc("Red");
    b1.move();
    b2.move("Fly");
}