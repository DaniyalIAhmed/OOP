// A2-Q1[22k-4601].cpp : This file is a solution to Assignment 2 Question 1
//

#include <iostream>
using namespace std;
class juice {
    float price;
    string ingredients[3], taste[2], name, id;
public:
    juice(float w, string x, string y,string z, string a , string b, string c, string d):price(w), name(c), id(d) {
        ingredients[0] = x;
        ingredients[1] = y;
        ingredients[2] = z;
        taste[0] = a, taste[1] = b;
    }
    void print(void) {
        cout << "\nJuice Price: " << price << "\nTaste: " << taste[0] << ", " << taste[1] << "\nName: " << name << "\nID: " << id << endl;
        cout << "Ingredients: ";
        for (int i = 0;i < 3;i++) {
            cout << ingredients[i]<<", ";
        }
        cout << endl;
    }
    float getPrice() {
        return price;
    }
};
class FruitJuice :public juice{
protected:
    string season;
public:
    FruitJuice(float w, string x, string y, string z, string a, string b, string c, string d, string e) :juice(w, x, y, z, a, b, c, d) {
        season = e;
    }
    void print(void) {
        juice::print();
        cout << "\nSeason: " << season << endl;
    }
};
class VegetableJuice: public juice {
protected:
    string origin;
public:
    VegetableJuice(float w, string x, string y, string z, string a, string b, string c, string d, string e) :juice(w, x, y, z, a, b, c, d) {
        origin = e;
    }
    void print(void) {
        juice::print();
        cout << "\nOrigin: " << origin << endl;
    }
};
class MixedJuice:public juice {
public:
    MixedJuice(float w, string x, string y, string z, string a, string b, string c, string d) :juice(w, x, y, z, a, b, c, d) {

    }
    void print(void) {
        juice::print();
        cout << "\nMixed Juice" << endl;
    }
};
class CitrusJuice : public FruitJuice {
public:
    CitrusJuice(float w, string x, string y, string z, string a, string b, string c, string d, string e) : FruitJuice(w, x, y, z, a, b, c, d, e) {

    }
    void print(void) {
        FruitJuice::print();
        cout << "\nCitrus Juice" << endl;
    }
};
class BerryJuice : public FruitJuice {
public:
    BerryJuice(float w, string x, string y, string z, string a, string b, string c, string d, string e) : FruitJuice(w, x, y, z, a, b, c, d, e) {

    }
    void print(void) {
        FruitJuice::print();
        cout << "\nBerry Juice" << endl;
    }
};
class TropicalJuice : public FruitJuice {
public:
    TropicalJuice(float w, string x, string y, string z, string a, string b, string c, string d, string e) : FruitJuice(w, x, y, z, a, b, c, d, e) {

    }
    void print(void) {
        FruitJuice::print();
        cout << "\nTopical Juice" << endl;
    }
};
class LeafyGreenJuice : public VegetableJuice {
public:
    LeafyGreenJuice(float w, string x, string y, string z, string a, string b, string c, string d, string e) : VegetableJuice(w, x, y, z, a, b, c, d, e) {
    }
    void print(void) {
        VegetableJuice::print();
        cout << "\nLeafy Green Juice" << endl;
    }
};
class RootVegetableJuice : public VegetableJuice {
public:
    RootVegetableJuice(float w, string x, string y, string z, string a, string b, string c, string d, string e) : VegetableJuice(w, x, y, z, a, b, c, d, e) {
    }
    void print(void) {
        VegetableJuice::print();
        cout << "\nRooted Vegetable Juice" << endl;
    }
};
class MixedVegetableJuice : public VegetableJuice {
public:
    MixedVegetableJuice(float w, string x, string y, string z, string a, string b, string c, string d, string e) : VegetableJuice(w, x, y, z, a, b, c, d, e) {
    }
    void print(void) {
        VegetableJuice::print();
        cout << "\nMixed Vegetable Juice" << endl;
    }
};
class FruitAndVeggieJuice : public MixedJuice {
public:
    FruitAndVeggieJuice(float w, string x, string y, string z, string a, string b, string c, string d) :MixedJuice(w, x, y, z, a, b, c, d) {

    }
    void print(void) {
        MixedJuice::print();
        cout << "\nFruit Veggie Juice" << endl;
    }
};
class SmoothieJuice : public MixedJuice {
public:
    SmoothieJuice(float w, string x, string y, string z, string a, string b, string c, string d) :MixedJuice(w, x, y, z, a, b, c, d) {

    }
    void print(void) {
        MixedJuice::print();
        cout << "\nSmoothie Juice" << endl;
    }
};
class sale {
private:
    string sId, cName;
    float totalBill;
    int nof, nov, nom;
public:
    sale(string x, string y, float z, int a, int b, int c) :sId(x), cName(y), totalBill(z), nof(a), nov(b), nom(c) {

    }
    sale(const sale& r1){
        sId = r1.sId;
        cName = r1.cName;
        totalBill = r1.totalBill;
        nof = r1.nof, nov = r1.nov, nom = r1.nom;
    }
    sale() {
    }
    sale operator+(sale s1) {
        sale s3;
        if (sId == s1.sId) {
            s3.totalBill = totalBill + s1.totalBill;
            s3.nof = nof + s1.nof;
            s3.nov = nov + s1.nov;
            s3.nom = nom + s1.nom;
            return s3;
        }
        else
            cout << "Error!" << endl;
    }
    void print() {
        cout << "Your Bill: " << endl;
        cout << "Name: " << cName << "\nSID: " << sId << "\nTotal Bill: " << totalBill << "\nNumber of Fruit Juice: " << nof << "\nNumber of Vegetable Juice: "
            << nov << "\nNumber of Mixed Juice: " << nom;
    }
};


int main()
{
    int choice, nof = 0, nom = 0, nov = 0, ctr1=0, ctr2 = 0;
    string Name, id;
    float total = 0, total1 = 0;
    cout << "Question 01\n";
    cout << "Enter your name: ";
    cin >> Name;
    cin.ignore();
    cout << "\nEnter your ID: ";
    cin >> id;
    ad:
    system("cls");
    cout << "Select Your choice: " << endl;
    cout << "1.Fruit Juice" << endl;
    cout << "2.Vegetable Juice" << endl;
    cout << "3.Mixed Juice" << endl;
    cout << "4.Check Out" << endl;
    cin >> choice;
    if (choice == 1) {
        system("cls");
        cout << "1. Citrus Juice" << endl;
        cout << "2. Berry Juice" << endl;
        cout << "3. Tropical Juice" << endl;
        nof++;
        ctr1 = 1;
        cin >> choice;
        if (choice == 1) {
            CitrusJuice c(399, "Oranges", "Lemons", "Grape Fruit", "Sweet", "Tangy", Name, id, "Spring and Winter");
            c.print();
            total += c.getPrice();
            cin >> choice;//Used for stopping the program to show the printing function only ;)
        }
        else if (choice == 2) {
            BerryJuice b(449, "Black Berries", "Lemons", "Grape Fruit", "Sweet", "Tangy", Name, id, "Spring");
            b.print();
            total += b.getPrice();cin >> choice;
        }
        else if (choice == 3) {
            TropicalJuice t(499, "Apples", "Pomegranites", "Bananas", "Sweet", "Tangy", Name, id, "All Year");
            t.print();
            total += t.getPrice();cin >> choice;
        }
        goto ad;
    }
    else if (choice == 2) {
        system("cls");
        cout << "1. Leafy Green Juice" << endl;
        cout << "2. Root Vegetable Juice" << endl;
        cout << "3. Mixed Vegetable Juice" << endl;
        cin >> choice;
        nov++;
        ctr2 = 1;
        if (choice == 1) {
            LeafyGreenJuice l(499, "Kale", "Spinach", "Celery", "Bitter", "Earthy", Name, id, "Leaf");
            l.print();total1 += l.getPrice();cin >> choice;
        }
        else if (choice == 2) {
            RootVegetableJuice r(549, "Carrot", "Reddish", "Sweet Potato", "Sour", "Earthy", Name, id, "Root");
            r.print();total1 += r.getPrice();cin >> choice;
        }
        else if (choice == 3) {
            MixedVegetableJuice m(699, "Karela", "Turai", "Loki", "Sour", "Bitter", Name, id, "Leaf");
            m.print();total1 += m.getPrice();cin >> choice;
        }
        goto ad;
    }
    else if (choice == 3) {
        system("cls");
        cout << "1. Fruit and Vegetable Juice" << endl;
        cout << "2. Smoothie Juice" << endl;
        cin >> choice;
        nom++;
        if (choice == 1) {
            FruitAndVeggieJuice fv(899, "Karela", "Apple", "Blue Berries", "Sweet", "Sour", Name, id);
            fv.print();total += fv.getPrice();cin >> choice;
        }
        else if (choice == 2) {
            SmoothieJuice sj(249, "Bananas", "Strawberries", "WaterMelon", "Sweet", "Creamy", Name, id);
            sj.print();total += sj.getPrice();cin >> choice;
        }
        goto ad;
    }
    else if (choice == 4) {
        if (ctr1 == 1 and ctr2 == 1) {
            sale sl1(id, Name, total, nof, 0, nom);
            sale sl2(id, Name, total1, 0, nov, 0);
            sale sl3 = sl1 + sl2;
            sl3.print();
        }
        else {
            sale sl1(id, Name, total, nof, nov, nom);
            sl1.print();
        }
    }
}
