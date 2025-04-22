#include <bits/stdc++.h>
using namespace std;
 
using vi = vector<int>;
using vll = vector<long long>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<long long>>;
 
#define test ll test; cin >> test; while (test--) 
#define ll long long
#define vinp(arr, n) vll arr(n); for (ll i=0; i<n; i++) cin >> arr[i];
#define bitvinp(n, size) vector<vector<ll>> bitarr(n, vector<ll>(size)); for (ll i=0; i<n; i++) { ll num; cin >> num; bitarr[i] = bitValue(num, size); }
#define check1 cout << "Hello" << endl;
#define check2 cout << "Hello2" << endl;
#define check3 cout << "Hello3" << endl;
 
const ll MAXN = 1000000;
 
template<ll N>
struct Sieve {
    bool is_prime[N];
    constexpr Sieve() : is_prime() {
        for (ll i = 2; i < N; i++) {
            is_prime[i] = true;
        }
        for (ll i = 2; i < N; i++) if (is_prime[i]) {
            for (ll j = 2 * i; j < N; j += i) {
                is_prime[j] = false;
            }
        }
    }
};
 
template<ll N>
struct SieveWrapper {
     static bool get(ll n) {
         Sieve<N> s;
         return s.is_prime[n];
    }
};
 
bool fast_is_prime(ll n) {
     return SieveWrapper<MAXN>::get(n);
}
 
bool isPrime(ll n){
    if (n == 1) return false;
    for (ll i=2; i*i <= n; i++) {
        if (n%i == 0) return false;
    }
    return true;
}
ll max(ll a, ll b) {
    return a > b ? a : b;
}
ll min(ll a, ll b) {
    return a < b ? a : b;
}
int gcd(int a, int b) {
    if (a == 0) return b;
    return gcd(b%a, a);
}
 
ll nC2 (ll n) {
    return n*(n-1)/2;
}
 
int binary_search(vector<ll> arr, ll value) {
    int low = 0;
    int high = arr.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == value) {
            return mid;
        } else if (arr[mid] < value) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return low; // Value not found  
}
 
//Competitve Progamming ki mkb
ll factorial(ll num) {
    ll prod = 1;
    for(ll i = 1; i <= num; i++) {
        prod *= i;
    }
    return prod;
}
 
//Competetive Programming ki mkc
 
vector<ll> bitValue(ll n, ll size) {
    vector<ll> bit(size, 0);
    int i = 0;
    while (n > 0) {
        bit[i] = n % 2;
        n /= 2;
        i++;
    }
    return bit;
}
 
ll bitToNum(vector<ll> bit) {
    ll num = 0;
    for (ll i=0; i<bit.size(); i++) {
        num += bit[i]*pow(2, i);
    }
    return num;
}
 
void print(auto arr) {
    for (auto a: arr) {
        cout << a << " ";
    }
    cout << endl;
}
 
void DFSUtil(vector<vector<ll>> adj, vector<bool> &visited, ll v, vector<ll> arr) {
    visited[v] = true;
    cout << v << " ";
    for (ll i=0; i<adj[v].size(); i++) {
        if (!visited[adj[v][i]]) {
            DFSUtil(adj, visited, adj[v][i], arr);
        }
    }
}
 
void DFS(vector<vector<ll>> adj, ll V, vector<ll> arr) {
    vector<bool> visited(V, false);
    for (ll i=0; i<V; i++) {
        if (!visited[i]) {
            DFSUtil(adj, visited, i, arr);
        }
    }
}
 
ll mex (vector<ll> arr) {
    sort(arr.begin(), arr.end());
    ll m = 0;
    for (ll i=0; i<arr.size(); i++) {
        if (arr[i] == m) {
            m++;
        }
    }
    return m;
}
 
long long binExpoMod(long long a, long long b, long long m) {
    long long res = 1;
    a = a % m;  // Update a if it is more than or equal to m
 
    while (b > 0) {
        if (b & 1) {
            res = (res * a) % m;
        }
        a = (a * a) % m;
        b >>= 1;
    }
 
    return res;
}

bool is_good_num(ll num, ll a, ll b) {
    while(num > 0) {
        ll digit = num % 10;
        if (digit != a && digit != b) {
            return false;
        }
        num /= 10;
    }
    return true;
}

int main() {
    // test {
        ll a1, b1, n; cin >> a1 >> b1 >> n;
        ll a = min(a1, b1);
        ll b = max(a1, b1);
        // cout << a << " " << b << " " << n;
        ll num = 1000000007;
        ll minsum = n * a;
        ll maxsum = n * b;
        // cout << minsum << " " << maxsum << endl;
        ll count = 0;
        for (ll i = 0; i <= n; i++) {
            ll curr_sum = i * a + (n - i) * b;
            if (is_good_num(curr_sum, a, b)) {
                count += factorial(n)/(factorial(i)*factorial(n-i));
                count = count % num;
            }
        }
        cout << count << endl;
    // }
}