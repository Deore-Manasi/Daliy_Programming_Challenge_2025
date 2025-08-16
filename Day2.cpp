//// Find Missing number problem.

#include<iostream>
using namespace std;
int main ()
{
    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int total = (n + 1) * (n + 2) / 2; // Sum of first n natural numbers
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    int missingNumber = total - sum;
    cout << "The missing number is: " << missingNumber << endl;


    return 0;
} 