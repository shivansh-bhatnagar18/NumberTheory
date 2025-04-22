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
    int a, b, c, x1, x2, y1, y2;
    cout << "Enter coefficients a, b and c for the equation ax + by + c = 0 and ranges for x1, x2, y1, y2: ";
    cin >> a >> b >> c >> x1 >> x2 >> y1 >> y2;

    int x, y;
    if (findSolution(a, b, -c, x, y)) {
        cout << "Solution exists: x = " << x << ", y = " << y << endl;
    } else {
        cout << "No solution exists for the given equation." << endl;
    }
    vector<pair<int, int>> solutions;
    int gcd = __gcd(a, b);
    int count = 0;
    if (gcd != 0) {
        for (int k = (x1 - x) / (b / gcd); k <= (x2 - x) / (b / gcd); ++k) {
            int newX = x + k * (b / gcd);
            int newY = y - k * (a / gcd);
            if (newX >= x1 && newX <= x2 && newY >= y1 && newY <= y2) {
                count++;
                solutions.push_back({newX, newY});
            }
        }
    }

    if (!solutions.empty()) {
        cout << count << " solutions in the given range:" << endl;
        for (const auto &sol : solutions) {
            cout << "x = " << sol.first << ", y = " << sol.second << endl;
        }
    } else {
        cout << "No solutions in the given range." << endl;
    }

    return 0;
}