#include <bits/stdc++.h>
using namespace std;
 
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int gcd_iterative(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int num1, num2;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    cout << "Recursive : " << gcd(num1, num2) << endl;
    cout << "Iterative : " << gcd_iterative(num1, num2) << endl;

    return 0;
}
