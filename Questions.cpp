// Questions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
class flower {
private:
    int n, k, w, *a;
public:
    flower(int x, int y, int z,int* p) {
        n = x, k = y, w = z, a = p;
    }
    void fn1() const {
        int min = 32000, i, ctr = 0, l=0;
        for (int j = 0;j < k;j++) {
            min = 32000, ctr = 0, l = 0;
            for (i = 0;i < n;i++) {
                if (a[i] < min) {
                    min = a[i];
                }
            }
            for (i = 0;i < n;i++) {
                if (a[i] == min) {
                    if (i + w >= n) {
                        ctr = 1;
                        break;
                    }
                    else if (i + w < n) {
                        ctr = 2;
                        break;
                    }
                }
            }
            for (i = i;l < w;i++, l++) {
                if (ctr == 2) {
                    a[i]++;
                }
            }
            for (i = n-w;i < n;i++) {
                if (ctr == 1)
                    a[i]++;
            }
        }
        cout << "The Answer is:\n";
        for (int k = 0;k < n;k++) {
            cout << a[k];
        }
    }
};
int main()
{
    int n= 0, k = 0, w = 0;
    cout << "Question-01\n";
    cout << "Enter the value of n, k, and w: ";
    cin >> n >> k >> w;
    int* a = new int[n];
    cout << "Enter values:" << endl;
    for (int i = 0;i < n;i++) {
        cin >> a[i];
    }
    const flower fl(n, k, w, a);
    fl.fn1();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
