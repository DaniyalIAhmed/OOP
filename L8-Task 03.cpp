// Task 03.cpp : This file is a solution of Lab 08
//

#include <iostream>
using namespace std;
class animal {
public:
    void eat() {
        cout << "Eaten Grass" << endl;
    }
    void play(){
        cout << "Playing in Nature!" << endl;
    }
};
class pet {
public:
    void eat() {
        cout << "Eaten Food" << endl;
    }
    void play() {
        cout << "Playing with Toys" << endl;
    }
};
class petanimal:public pet, public animal {
public:
    void eat() {
        cout << "I can eat food as well as anything eatable" << endl;
    }
    void play() {
        cout << "I can either play with toys or anythingi find interesting!" << endl;
    }
};
int main()
{
    cout << "Task 03\n";
    petanimal p1;
    p1.eat();//Getting confused on which one to call
    p1.play();//Same is the case with this one!
    p1.pet::play();
    p1.pet::eat();
    p1.animal::play();
    p1.animal::eat();
}