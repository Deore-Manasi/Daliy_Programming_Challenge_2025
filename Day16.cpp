////LCM of two numbers
#include <iostream>
using namespace std;

// Function to compute GCD using Euclidean Algorithm
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to compute LCM
long long lcm(long long n, long long m) {
    return (n / gcd(n, m)) * m;  // divide first to prevent overflow
}

int main() {
    long long N, M;
    cout<<"Enter the two numbers:";
    cin >> N >> M;
    cout << lcm(N, M) << endl;
    return 0;
}
