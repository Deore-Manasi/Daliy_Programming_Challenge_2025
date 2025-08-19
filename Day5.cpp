//// Leader elements in an array
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> findLeaders(vector<int>& arr) {
    int n = arr.size();
    vector<int> leaders;
    
    int maxRight = arr[n-1];  // last element is always leader
    leaders.push_back(maxRight);

    // Traverse from right to left
    for (int i = n-2; i >= 0; i--) {
        if (arr[i] >= maxRight) {
            leaders.push_back(arr[i]);
            maxRight = arr[i];
        }
    }

    reverse(leaders.begin(), leaders.end()); // put in correct order
    return leaders;
}

int main() {
    vector<int> arr = {16, 17, 4, 3, 5, 2};
    vector<int> leaders = findLeaders(arr);

    cout << "Leaders: ";
    for (int x : leaders) cout << x << " ";
    return 0;
}
