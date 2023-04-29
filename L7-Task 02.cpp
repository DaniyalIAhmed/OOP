// Task 02.cpp : This file is a solution to a problem in Lab 07
//

#include <iostream>
using namespace std;
class product {
protected:
    int pId, quantity;
    string pName, category, supplier;
    float price;
public:
    void addStock(int x) {
        quantity += x;
    }
    void add(int x, int y, string a, string b, string c, float d){
        pId = x, quantity = y, pName = a, category = b, supplier = c, price = d;
    }
    void remove() {
        pId = 00, quantity = 0, pName = "", category = "", supplier = "", price = 0.00;
    }
    string getName() {
        return pName;
    }
    float getPrice() {
        return price;
    }
    int getQuantity() {
        return quantity;
    }
    void details() {
        cout << "\nProduct Name: " << pName;
        cout << "\nProduct Id: " << pId;
        cout << "\nProduct Quantity: " << quantity;
        cout << "\nProduct Category: " << category;
        cout << "\nProduct Supplier: " << supplier;
        cout << "\nProduct Price: " << price;
    }
};
class category: protected product {
protected:
    int cId;
    string cName;
    product p[10];
public:
    static int ctr;
    void addProduct() {
        cout << "Enter Details: " << endl;
        cout << "\nEnter Product Id: ";cin >> pId;
        cout << "\nEnter Product Quantity: ";cin >> quantity;
        cout << "\nEnter Product Name: ";cin >> pName;
        cout << "\nEnter Product Category: ";cin >> product::category;
        cout << "\nEnter Product Supplier: ";cin >> supplier;
        cout << "\nEnter Product Price: ";cin >> price;
        p[ctr].add(pId, quantity, pName, product::category, supplier, price);
        ctr++;
    }
    void remProduct() {
        cout << "\nEnter index number: ";
        int x;
        cin >> x;
        p[ctr].remove();
    }
    product* getProduct() {
        return p;
    }
    void addCategory(string x, int y) {
        cName = x, cId = y;
    }
    void search(string x) {
        for (int i = 0;i < ctr;i++) {
            if (x == p[i].getName()) {
                cout << "Product Details:" << endl;
                p[i].details();
            }
        }
    }
    void search(float x) {
        for (int i = 0;i < ctr;i++) {
            if (x == p[i].getPrice()) {
                cout << "Product Details:" << endl;
                p[i].details();
            }
        }
    }
    void search(int x) {
        for (int i = 0;i < ctr;i++) {
            if (x == p[i].getQuantity()) {
                cout << "Product Details:" << endl;
                p[i].details();
            }
        }
    }
};
int category::ctr = 0;
class supplier:protected category {
private:
    int sId;
    string sName;
    product p1[5];
public:
    static int ctr1;
    void addSupplier(string x, int y) {
        sId = y, sName = x;
    }
    void addProduct() {
        string x, y;
        cout << "Enter Details: " << endl;
        cout << "\nEnter Product Id: ";cin >> pId;
        cout << "\nEnter Product Quantity: ";cin >> quantity;
        cout << "\nEnter Product Name: ";cin >> pName;
        cout << "\nEnter Product Category: ";cin >> x;
        cout << "\nEnter Product Supplier: ";cin >> y;
        cout << "\nEnter Product Price: ";cin >> price;
        p[ctr].add(pId, quantity, pName, x, y, price);
        ctr1++;
    }
    void remProduct() {
        cout << "\nEnter index number: ";
        int x;
        cin >> x;
        p1[ctr].remove();
    }
    product* getProduct() {
        return p1;
    }
};
int supplier::ctr1 = 0;
int main()
{

    int choice, in;
    cout << "Task 02\n";
    category c;
    supplier s;
abc:
    system("cls");
    cout << "Select from the following: " << endl;
    cout << "1.Add product to category\n";
    cout << "2.Add product to supplier\n";
    cout << "3.Remove product from category\n";
    cout << "4.Remove product from supplier\n";
    cout << "5.Add Category\n";
    cout << "6.Add Suppplier\n";
    cout << "7.Get product Details from category\n";
    cout << "8.Get product Details from supplier\n";
    cout << "9.Search\n";
    cout << "10.Exit\n";
    cin >> choice;
    if (choice == 1) {
        c.addProduct();
        cout << "Enter anything:";
        cin >> in;
        goto abc;
    }
    else if (choice == 2) {
        s.addProduct();
        cout << "Enter anything:";
        cin >> in;
        goto abc;
    }
    else if (choice == 3) {
        c.remProduct();
        cout << "Enter anything:";
        cin >> in;
        goto abc;
    }
    else if (choice == 4) {
        s.remProduct();
        cout << "Enter anything:";
        cin >> in;
        goto abc;
    }
    else if (choice == 5) {
        string a;int b;
        cout << "\nEnter Category Name: ";
        cin >> a;
        cout << "\nEnter Category Id: ";
        cin >> b;
        c.addCategory(a, b);
        cout << "Enter anything:";
        cin >> in;
        goto abc;
    }
    else if (choice == 6) {
        string a;int b;
        cout << "\nEnter Supplier Name: ";
        cin >> a;
        cout << "\nEnter Supplier Id: ";
        cin >> b;
        c.addCategory(a, b);
        cout << "Enter anything:";
        cin >> in;
        goto abc;
    }
    else if (choice == 7) {
        product* ptr = c.getProduct();
        for (int i = 0;i < category::ctr;i++) {
            ptr[i].details();
        }
        cout << "Enter anything:";
        cin >> in;
        goto abc;
    }
    else if (choice == 8) {
        product* ptr = s.getProduct();
        for (int i = 0;i < supplier::ctr1;i++) {
            ptr[i].details();
        }
        cout << "Enter anything:";
        cin >> in;
        goto abc;
    }
    else if (choice == 9) {
        string name;
        cout << "\nEnter product Name: ";
        cin >> name;
        c.search(name);
        cout << "Enter anything:";
        cin >> in;
        goto abc;
    }
    else if (choice == 10) {
        exit(1);
    }
}