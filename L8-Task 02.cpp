// Task02.cpp : This file is a solution of Lab 08
//

#include <iostream>
using namespace std;
class bird {
private:
    string color, feather;
public:  
    void move() {
        cout << "A simple bird!" << endl;
    }
};
class wbird : public bird {
public:
    void move() {
        cout << "A walking bird!" << endl;
    }
};
class sbird : public bird {
public:
    void move() {
        cout << "A swimming bird!" << endl;
    }
};
class fbird : public bird {
public:
    void move() {
        cout << "A flying bird!" << endl;
    }
};
int main()
{
    cout << "Task 02\n\n";
    wbird wb;
    sbird sb;
    fbird fb;
    fb.move();
    sb.move();
    wb.move();
    wb.bird::move();
}
