// Task 01.cpp : This file is a solution to a problem in Lab 07
//

#include <iostream>
using namespace std;
class menu {
private:
    string dishName;
    float dishPrice;
public:
    void add(string x, float y){
        dishName = x, dishPrice = y;
    }
};
class restaurant {
private:
    string name, address, phone;
    float rating;
    menu m[10];
public:
    void menuFiller() {
        string x;
        float y;
        int z;
        cout << "Enter the total number of dishes: ";cin >> z;
        cout << "\nEnter Dish details:";
        for (int i = 0;i < z;i++) {
            cout << "\nDish Name: ";cin >> x;
            cout << "\nDish Price: ";cin >> y;
            m[i].add(x, y);
        }
    }
    menu* getMenu() {
        return m;
    }
    restaurant(string x, string y, string z, float a) {
        name = x, address = y, phone = z, rating = a;
    }
    restaurant(){}
};
class italianRestaurant: public restaurant{
private:
    string pizzaType, pastaType;
public:
    void makePasta(string x) {
        cout << "Making Pasta: " << x <<endl;
    }
    void makePizza(string x) {
        cout << "Making Pizza: " << x <<endl;
    }
    italianRestaurant(string x, string y, string z, float a, string b, string c) :restaurant(x, y, z, a) {
        pizzaType = b, pastaType = c;
    }
    italianRestaurant(){}
};
class mexicanRestaurant: public restaurant {
private:
    int spiceLevel;string salsaType;
public:
    mexicanRestaurant(){}
    mexicanRestaurant(string x, string y, string z, float a, int b, string c) :restaurant(x, y, z, a) {
        spiceLevel = b, salsaType = c;
    }
    void makeTaco(string x) {
        cout << "Making Taco with " << x << " filling" << endl;
    }
    void makeBurrito(string x) {
        cout << "Making Burrito with " << x << " filling" << endl;
    }
};
int main()
{
    cout << "Hello World!\n";
    restaurant r;
    italianRestaurant r1;
    mexicanRestaurant r2;
}
