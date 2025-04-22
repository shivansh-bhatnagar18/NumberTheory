#include <bits/stdc++.h>
using namespace std;

int main() {
    string num; cin >> num;
    int s = num.size();
    if (s == 11) {
        int sum = 0;
        for (int i = 0; i < 11; i++) {
            if(i % 2 == 0) {
                sum += (num[i] - '0') * 3;
            } else {
                sum += (num[i] - '0');
            }
        }
        cout << min(sum % 10, 10 - sum % 10) << endl;
    } else {
        int sum = 0;
        for (int i = 0; i < 12; i++) {
            if(i % 2 == 0) {
                sum += (num[i] - '0') * 3;
            } else {
                sum += (num[i] - '0');
            }
        }
        if (sum % 10 == 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}