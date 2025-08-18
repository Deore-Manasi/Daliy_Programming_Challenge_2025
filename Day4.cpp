#include <vector>
#include <iostream>
using namespace std;

void merge(vector<int>& arr1, vector<int>& arr2, int m, int n) {
    for (int i = 0; i < m; i++) {
        if (arr1[i] > arr2[0]) {
            // Swap
            swap(arr1[i], arr2[0]);

            
            int first = arr2[0];
            int k;
            for (k = 1; k < n && arr2[k] < first; k++) {
                arr2[k-1] = arr2[k];
            }
            arr2[k-1] = first;
        }
    }
}

int main() {
    vector<int> arr1 = {1, 3, 5, 7};
    vector<int> arr2 = {2, 4, 6, 8};

    merge(arr1, arr2, arr1.size(), arr2.size());

    cout << "arr1 = ";
    for (int x : arr1) cout << x << " ";
    cout << "\narr2 = ";
    for (int x : arr2) cout << x << " ";
    cout << endl;

    return 0;
}
