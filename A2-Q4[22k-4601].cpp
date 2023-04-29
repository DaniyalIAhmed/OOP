// A2-Q4[22k-4601].cpp : This file is a solution to Assignment 2 Question 4 By 22k-4601, Daniyal Ahmed
//

#include <iostream>
using namespace std;
class gameObject {
public:
    const string name;
    int X, Y;
public:
    gameObject(string x, int y, int z) :X(y), Y(z), name(x) {

    }
    gameObject() {}
    virtual void draw() {
        cout << "This is Game Object Class" << endl;
    }
    gameObject(string x) : name(x) {}
};
class player :public gameObject {
protected:
    float health;
public:
    player(string w, float x, int y, int z) : gameObject(w, y, z) {
        health = x;
    }
    bool operator==(player c1) {
        if (this->health == c1.health)
            return 1;
        else
            return 0;
    }
    void draw() {
        cout << "This is Player Class" << endl;
    }
};
class enemy :public gameObject {
protected:
    float damage;
public:
    enemy(string w, float x, int y, int z) : gameObject(w, y, z) {
        damage = x;
    }
    void draw() {
        cout << "This is Enemy Class" << endl;
    }
};
class powerUp :public gameObject {
protected:
    string effects;
public:
    powerUp(string w, int x, int y, string z) :gameObject(w, x, y), effects(z) {

    }
    void draw() {
        cout << "This is Power Up Class" << endl;
    }
};
class game {
private:
public:
    gameObject** ptr;
    game() {
        ptr = new gameObject * [3];
    }
    void DrawAll() {
        for (int i = 0;i < 3;i++) {
            ptr[i]->draw();
        }
    }
    void addObjects(gameObject* p1, gameObject* e1, gameObject* pw1) {
        ptr[0] = p1;
        ptr[1] = e1;
        ptr[2] = pw1;
    }
};
int main()
{
    string sId;
    cout << "Question 04\n";
    cout << "Enter your Student ID: ";
    cin >> sId;
    cout << endl;
    int ctr = 0;
    for (int i = 0;i < 8;i++) {
        if (i < 2) {
            if (sId.at(i) <= 48 && sId.at(i) >= 57) {
                cout << "Invalid Id!" << endl;
                ctr = 1;
                break;
            }
        }
        else if (i < 4) {
            if (sId.at(i) >= 48 && sId.at(i) <= 57) {
                cout << "Invalid Id!" << endl;
                ctr = 1;
                break;
            }
        }
        else if (i < 8) {
            if (sId.at(i) <= 48 && sId.at(i) >= 57) {
                cout << "Invalid Id!" << endl;
                ctr = 1;
                break;
            }
        }
    }
    if (ctr == 0) {
        cout << "Valid id!\n";
        player p1(sId, 89, 0, 0);
        player p2(sId, 89, 10, 20);
        player* p = new player(sId, 80.9, 10, 20);
        enemy* e = new enemy(sId, 70.8, 20, 10);
        powerUp* pu = new powerUp(sId, 20, 10, "toxic effect");
        game g;
        g.addObjects(p, e, pu);
        g.DrawAll();
        if (p1 == p2)
        {
            cout << "Player 1 and Player 2 have the same health." << endl;
        }
        else
        {
            cout << "Player 1 and Player 2 have different health." << endl;
        }
        return 0;
    }

}