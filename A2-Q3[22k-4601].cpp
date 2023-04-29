// A2-Q3[22k-4601].cpp : This file is a solution to Assignment 2 Question 3
//

#include <iostream>
using namespace std;
class product {
protected:
    string name;
    float price;
public:
    product(string x, float y) {
        name = x, price = y;
    }
    product(){}
    float virtual getdiscountedprice() {
        float discount = price;
        discount -= price * 0.05;
        return discount;
    }
    void virtual printDetails(){
        cout << "Product: " << name << ", Price: " << price << endl;
    }
    product operator&(const product& p1) {
        product temp;
        temp.name = name + " & " + p1.name;
        temp.price = ((price + p1.price) / 2);
        return temp;
    }
    string getName() {
        return name;
    }
};
class book : public product {
private:
    string author;
public:
    float getdiscountedprice() {
        return (price = price - price*0.05);
    }
    void printDetails() {
        cout << "Product: " << name << ", Price: " << price << ", Author: " << author << endl;
    }
    
};
class electronics : public product {
private:
    string brand;
public:
    void printDetails() {
        cout << "Product: " << name << ", Price: " << price << ", Brand: " << brand << endl;
    }
};
class clothing : public product {
private:
    string size;
public:
    float getdiscountedprice() {
        return (price = price - price * 0.1);
    }
    void printDetails() {
        cout << "Product: " << name << ", Price: " << price << ", Size: " << size << endl;
    }
};
class customer {
protected:
    string name;
    float balance;
public:
    customer(string x, float y) {
        name = x, balance = y;
    }
    customer(){}
    void virtual buyProduct(product*ptr) {
        float dis = ptr->getdiscountedprice();
        if (dis > balance) {
            cout << "Insufficient Balance!" << endl;
        }
        else {
            balance = balance - dis;
            cout << name << " has bought " << ptr->getName() << " for $" << dis << ". Your new balance is " << balance << endl;
        }
    }
};
class vipCustomer: public customer {
public:
    vipCustomer(string x, float y): customer(x, y) {

    }
    vipCustomer(){}
    void buyProduct(product* ptr) {
        float dis = ptr->getdiscountedprice();
        dis = dis - dis * 0.05;
        if (dis > balance) {
            cout << "Insufficient Balance!" << endl;
        }
        else {
            balance = balance - dis;
            cout << name << " is a VIP customer who has bought " << ptr->getName() << " for $" << dis << ". Your new balance is $" << balance << endl;
        }
    }
};
int main()
{
   cout << "Question 3\n";
   string id;int choice;float bal;
   product p1("Book", 10.0);
   product p2("Pen", 2.0);
   cout << "Enter your id: ";
   cin >> id;
   //Part A:
   cout << "\nAre you a VIP customer?\n1.Yes\n2.No\n";
   cin >> choice;
   cout << "Enter your balance: ";
   cin >> bal;
   if (choice == 1) {
       vipCustomer v1(id, bal);
       cout << "Select Products to Buy:\n1.Book\n2.Pen\n";
       cin >> choice;
       if (choice == 1) {
           v1.buyProduct(&p1);
       }
       else if (choice == 2) {
           v1.buyProduct(&p2);
       }
   }
   else if (choice == 2) {
       customer c1(id, bal);
       cout << "Select Products to Buy:\n1.Book\n2.Pen\n";
       cin >> choice;
       if (choice == 1) {
           c1.buyProduct(&p1);
       }
       else if (choice == 2) {
           c1.buyProduct(&p2);
       }
   }
   //Part B:
   product p3 = p1 & p2;
   cout << endl;
   cout << endl << "Part B:\n";
   p3.printDetails();
}