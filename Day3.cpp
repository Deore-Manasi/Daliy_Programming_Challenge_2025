////Exact one duplicate in an array
#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std;
int main(){

    vector<int> arr = {3, 1, 3, 4, 2}; 
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
    
    if(dup == -1) {
        cout << "No duplicate found." << endl;
    }
    
    
    
    
    return 0;
}