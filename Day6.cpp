////Find subarray with zero sum
#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> zeroSumSubarrays(vector<int>& arr) {
    vector<pair<int, int>> result;

    // Check every possible subarray
    for (int i = 0; i < arr.size(); i++) {
        int sum = 0;
        for (int j = i; j < arr.size(); j++) {
            sum += arr[j];
            if (sum == 0) {
                result.push_back({i, j});
            }
        }
    }
    return result;
}

int main() {
    vector<int> arr = {1, 2, -3, 3, -1, 2};
    vector<pair<int, int>> ans = zeroSumSubarrays(arr);

    for (auto p : ans) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
}
