#include <bits/stdc++.h>
using namespace std;

tuple<int, int, int> extendedGCD(int a, int b) {
    if (b == 0) {
        return {a, 1, 0};
    }
    int gcd, x1, y1;
    tie(gcd, x1, y1) = extendedGCD(b, a % b);
    int x = y1;
    int y = x1 - (a / b) * y1;
    return {gcd, x, y};
}


bool findSolution(int a, int b, int c, int &x, int &y) {
    int gcd, x0, y0;
    tie(gcd, x0, y0) = extendedGCD(a, b);
    if (c % gcd != 0) {
        return false;
    }
    x = x0 * (c / gcd);
    y = y0 * (c / gcd);
    return true;
}

int main() {
    int a, b, c;
    cout << "Enter coefficients a, b and c for the equation ax + by = c: ";
    cin >> a >> b >> c;

    int x, y;
    if (findSolution(a, b, c, x, y)) {
        cout << "Solution exists: x = " << x << ", y = " << y << endl;
    } else {
        cout << "No solution exists for the given equation." << endl;
    }

    return 0;
}