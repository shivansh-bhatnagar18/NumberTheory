#include <bits/stdc++.h>
using namespace std;

vector<int> primeFactors(int n) {
    vector<int> factors;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }
    if (n > 1) {
        factors.push_back(n);
    }
    return factors;
}

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
    int a, b; cin >> a >> b;
    vector<int> primes = primeFactors(b);
    for (int prime : primes) {
        cout << prime << " ";
    }
    cout << endl;
    vector<pair<int, int>> eqs;
    bool nosol = false;
    for (int i = 0; i < primes.size(); i++) {
        eqs.push_back({a % primes[i], primes[i]});
        cout << eqs[i].first << endl;
        if (sqrt(eqs[i].first) != (int)sqrt(eqs[i].first)) {
            cout << "No Solutions Exists" << endl;
            nosol = true;
            break;
        }
    }
    if (nosol) {
        return 0;
    }
    vector<pair<int, int>> eqsriyal;
    for (int i = 0; i < primes.size(); i++) {
        eqsriyal.push_back({sqrt(eqs[i].first), eqs[i].second});
        eqsriyal.push_back({eqs[i].second - sqrt(eqs[i].first), eqs[i].second});    
    } 
    int prodModulo = 1;
    for (auto &eq : eqs) {
        prodModulo *= eq.second;
    }

    int x = 0;
    int a1 = eqsriyal[0].first;
    int n1 = eqsriyal[0].second;
    int a2 = eqsriyal[2].first;
    int n2 = eqsriyal[2].second;
    int M1 = prodModulo / n1;
    int M2 = prodModulo / n2;
    int MiInverse1 = modularInverse(M1, n1);
    int MiInverse2 = modularInverse(M2, n2);
    x += a1 * M1 * MiInverse1;
    x += a2 * M2 * MiInverse2;

    cout << "Solution: " << x % prodModulo << endl;

    x = 0;
    a1 = eqsriyal[0].first;
    n1 = eqsriyal[0].second;
    a2 = eqsriyal[3].first;
    n2 = eqsriyal[3].second;
    M1 = prodModulo / n1;
    M2 = prodModulo / n2;
    MiInverse1 = modularInverse(M1, n1);
    MiInverse2 = modularInverse(M2, n2);
    x += a1 * M1 * MiInverse1;
    x += a2 * M2 * MiInverse2;

    cout << "Solution: " << x % prodModulo << endl;

    x = 0;
    a1 = eqsriyal[1].first;
    n1 = eqsriyal[1].second;
    a2 = eqsriyal[2].first;
    n2 = eqsriyal[2].second;
    M1 = prodModulo / n1;
    M2 = prodModulo / n2;
    MiInverse1 = modularInverse(M1, n1);
    MiInverse2 = modularInverse(M2, n2);
    x += a1 * M1 * MiInverse1;
    x += a2 * M2 * MiInverse2;

    cout << "Solution: " << x % prodModulo << endl;

    x = 0;
    a1 = eqsriyal[1].first;
    n1 = eqsriyal[1].second;
    a2 = eqsriyal[3].first;
    n2 = eqsriyal[3].second;
    M1 = prodModulo / n1;
    M2 = prodModulo / n2;
    MiInverse1 = modularInverse(M1, n1);
    MiInverse2 = modularInverse(M2, n2);
    x += a1 * M1 * MiInverse1;
    x += a2 * M2 * MiInverse2;

    cout << "Solution: " << x % prodModulo << endl;

    return 0;
}