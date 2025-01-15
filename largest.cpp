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
    cout << "Enter two numbers (largest factors): ";
    cin >> num1 >> num2;

    int gcdnum = gcd(num1, num2);
    //the number x shall be gcd * (num1 / gcd) * (num2 / gcd)
    int rem1 = num1 / gcdnum;
    int rem2 = num2 / gcdnum;
    int bigger = rem1 > rem2 ? rem1 : rem2;
    // cout << bigger << endl;
    int ans = gcdnum * rem1 * rem2;
    if (rem1 == 1 || rem2 == 1) {
        cout << "The largest factor is : " << (ans * (bigger + 1)) / bigger << endl;
    } else {
        cout << "The largest factor is " << ans << endl;
    }
    return 0;
}
