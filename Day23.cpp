////sliding Window Maximum problem
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& arr, int k) {
    deque<int> dq; // will store indexes
    vector<int> result;

    for (int i = 0; i < arr.size(); i++) {
        // 1. Remove elements out of this window
        if (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }

        // 2. Remove smaller elements (they won’t be needed)
        while (!dq.empty() && arr[dq.back()] < arr[i]) {
            dq.pop_back();
        }

        // 3. Add current element index
        dq.push_back(i);

        // 4. Window is valid only when i >= k-1
        if (i >= k - 1) {
            result.push_back(arr[dq.front()]);
        }
    }

    return result;
}

int main() {
    vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> res = maxSlidingWindow(arr, k);

    for (int num : res) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
