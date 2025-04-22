#include <iostream>
#include <vector>
#include <numeric> // for std::gcd in C++17 or later
using namespace std;

// Function to compute GCD of a vector
int gcdOfVector(const vector<int>& nums) {
    int result = nums[0];
    for (size_t i = 1; i < nums.size(); ++i) {
        result = gcd(result, nums[i]);
    }
    return result;
}

int main() {
    int n;
    cout << "Enter size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter array elements: ";
    for (int& num : arr) {
        cin >> num;
    }

    int totalSubsequences = (1 << n); // 2^n subsets

    cout << "GCDs of all non-empty subsequences:\n";
    for (int mask = 1; mask < totalSubsequences; ++mask) {
        vector<int> subseq;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                subseq.push_back(arr[i]);
            }
        }
        int subseqGCD = gcdOfVector(subseq);
        cout << "Subsequence GCD: " << subseqGCD << endl;
    }

    return 0;
}
