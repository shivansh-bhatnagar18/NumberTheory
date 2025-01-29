#include <bits/stdc++.h>
using namespace std;

int modularInverse(int a, int m) {
    int m0 = m;
    int y = 0, x = 1;
    if (m == 1) {
        return 0;
    }
    while (a > 1) {
        int q = a / m;
        int t = m;
        m = a % m;
        a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0) {
        x += m0;
    }
    return x;
}

int main() {
    int a, n, b, m, c, p;
    cin >> a >> n >> b >> m >> c >> p;
    int prodModulo = n * m * p;
    vector<int> Mi;
    for (int i = 0; i < 3; i++) {
        Mi.push_back(prodModulo / (i == 0 ? n : (i == 1 ? m : p)));
    }
    vector<int> MiInverse;
    for (int i = 0; i < 3; i++) {
        MiInverse.push_back(modularInverse(Mi[i], i == 0 ? n : (i == 1 ? m : p)));
    }
    int x = 0;
    for (int i = 0; i < 3; i++) {
        x += (i == 0 ? a : (i == 1 ? b : c)) * Mi[i] * MiInverse[i];
    }
    cout << x % prodModulo << endl;

}