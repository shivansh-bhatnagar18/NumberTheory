#include <bits/stdc++.h>
using namespace std;

int nCr (int n, int r, int mod) {
    if (r > n) {
        return 0;
    }
    if (r == 0 || r == n) {
        return 1;
    }
    int dp[n + 1][r + 1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= min(i, r); j++) {
            if (j == 0 || j == i) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % mod;
            }
        }
    }
    return dp[n][r];
}   

int main() {
   int r, n , m;
    cin >> r >> n >> m;
     cout << nCr(n, r, m) << endl;
}
