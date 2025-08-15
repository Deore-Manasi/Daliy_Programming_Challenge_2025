//// Sort o's and 1's and 2's in an array
#include <iostream>
#include <vector>
using namespace std;

void sortArr(vector<int>& arr) {
    int low = 0, mid = 0;
    int high = arr.size() - 1;

    while (mid <= high) {
        if (arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1) {
            mid++;
        }
        else { // arr[mid] == 2
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main() {
    vector<int> arr = {{0, 1, 2, 1, 0, 2, 1, 0} };
    //{2, 2, 2, 2} {0, 0, 0, 0}
        
    sortArr(arr);
    for (int num : arr) cout << num << " ";
    cout << endl;
    
    return 0;
}
