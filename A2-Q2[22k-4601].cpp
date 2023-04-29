// A2-Q2[22k-4601].cpp : This file is a solution to Assignment 2 Question 2
//

#include <iostream>
using namespace std;
class course {
protected:
    string cName, cCode;int cHours;
public:
    course(string x, string y, int z) : cName(x), cCode(y), cHours(z) {

    }
    course(){}
    void print(bool x) {
        if(x==0)
        cout << "Course Name: " << cName << "\nCourse Code: " << cCode << "\nCredit Hours: " << cHours << "\nGrade: Locked Grades";
        else
        cout << "Course Name: " << cName << "\nCourse Code: " << cCode << "\nCredit Hours: " << cHours << "\nGrade: ";
        
    }
    void setn(string x) {
        cName = x;
    }
    void setc(string x) {
        cCode = x;
    }
    void seth(int x) {
        cHours = x;
    }
    void setall(string x, string y, int z) {
        cName = x, cCode = y, cHours = z;
    }
    int getc() {
        return cHours;
    }
};
class student {
protected:
    string id, name;
    int noc;
    course* ptr;
    string* grade;
    bool fee;
public:
    student(string w, string x, int y, bool z) : id(w), name(x), noc(y), fee(z) {
        ptr = new course[noc];
        grade = new string[noc];
    }
    student(){}
    void setall(string w, string x, int y, bool z){
        id = w, name = x, noc = y, fee = z;
        ptr = new course[noc];
        grade = new string[noc];
    }
    void getcourses() {
        //Course Array Filler
        string x, y; int z;
        cout << "Enter course information:" << endl;
        for (int i = 0;i < noc;i++) {
            cout << "Enter Course Name: ";
            cin >> x;
            cout << "\nEnter Course Code: ";
            cin >> y;
            cout << "\nEnter Credit Hour: ";
            cin >> z;
            cout << endl;
            ptr[i].setall(x, y, z);
            cout << "\nEnter Grade: ";
            cin >> grade[i];
        }
    }
    int calC() {//Calculating Credit Hours...
        int cH = 0;
        for (int i = 0;i < noc;i++) {
            cH += ptr[i].getc();
        }
        return cH;
    }
    void calGpa() {//The question asks to get input of marks but only specifies the grades and grade equivalent so taking grades only :
        double marks = 0.0;
        for (int i = 0;i < noc;i++) {
            if (grade[i] == "A") {
                marks += (ptr[i].getc() * 4.00);
            }
            else if (grade[i] == "A-") {
                marks += (ptr[i].getc() * 3.66);
            }
            else if (grade[i] == "B+") {
                marks += (ptr[i].getc() * 3.33);
            }
            else if (grade[i] == "B") {
                marks += (ptr[i].getc() * 3.00);
            }
            else if (grade[i] == "B-") {
                marks += (ptr[i].getc() * 2.66);
            }
            else if (grade[i] == "C+") {
                marks += (ptr[i].getc() * 2.33);
            }
            else if (grade[i] == "C") {
                marks += (ptr[i].getc() * 2.00);
            }
            else if (grade[i] == "D") {
                marks += (ptr[i].getc() * 1.00);
            }
            else if (grade[i] == "D") {
                marks += (ptr[i].getc() * 0.00);
            }
        }
        cout << "\nSemester GPA: " << (marks / calC()) << endl;
        marks = marks / calC();
        cout << "Percentage GPA: " << ((marks / 4.0) * 100) << endl;
    }
    void print(double x) {
        int c;
        cout << "\nStudent Name: " << name << "\nStudent ID: " << id << "\nNumber of Courses Enrolled: " << noc << endl << "Course info:\n";
        for (int i = 0;i < noc;i++) {
            ptr[i].print(fee);
            if (fee == 0) {
                cout << "\n";
            }
            else {
                cout << grade[i] << "\n";
            }
        }
        if (fee == 0) {
            double fee;int ch;
            fee = x + x * 0.05;
            ch = calC();
            fee = fee * ch;
            cout << "\nTuition Fee Unpaid" << endl;
            cout << "Amount payable: " << fee << endl;
        }
        else
            cout << "Fee paid" << endl;
        c = calC();
        cout << "Total Credit Hours: " << c << endl;
    }
};
int main()
{
    int nos, num, credits, n;bool fee;double fees = 0.0;
    string name, rn, id;
    cout << "Question 2\n";
    cout << "Enter your ID: ";
    cin >> id;
    fees = (double(id.at(0)) - 48);
    fees *= 10.0;
    fees+= (double(id.at(0)) - 48);
    fees /= 2.0;
    fees = fees * 1000;
    nos = int(id.at(5)) - 48;
    student* sp = new student[nos];
    cout << "Enter data for " << nos << " students: " << endl;
    for (int i = 0;i < nos;i++) {
        cout << "Enter Name: ";
        cin >> name;
        cout << "\nEnter student id: ";
        cin >> rn;
        cout << "\nEnter number of courses: ";
        cin >> num;
        cout << "\nIs Fee paid for this student?\n1 for paid\n0 for unpaid\n";
        cin >> fee;
        sp[i].setall(rn, name, num, fee);
        sp[i].getcourses();
        sp[i].print(fees);
        sp[i].calGpa();
    }
}
