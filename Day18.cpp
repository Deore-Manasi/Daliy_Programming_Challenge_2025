//// count the number of divisors of a given integer N
#include <iostream>
#include <cmath>
using namespace std;

int countDivisors(long long n) {
    int count = 0;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            if (i * i == n) count++; // Perfect square, count once
            else count += 2;         // Count both i and n/i
        }
    }
    return count;
}

int main() {
    long long N;
    cout<<"Enter the number !!";
    cin >> N;
    cout << countDivisors(N) << endl;
    return 0;
}
