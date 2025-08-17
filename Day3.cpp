////Exact one duplicate in an array
#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std;
int main(){

    vector<int> arr = {1, 2, 3, 50000, 99999, 50000}; // Example array with one duplicate
    int n = arr.size();
    sort(arr.begin(), arr.end()); // Sort the array
    int dup =-1;
    for(int i =0;i<n-1;i++){
        if(arr[i]==arr[i+1]){
            dup = arr[i];
            break;
        }
    }
    cout<< "The duplicate element is: " << dup << endl;
    // Output: The duplicate element is: 3
    if(dup == -1) {
        cout << "No duplicate found." << endl;
    }
    
    
    
    
    return 0;
}