////Prime Factorization
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<long long> primeFactorization(long long n) {
    vector<long long> factors;

    // Step 1: Divide by 2 until odd
    while (n % 2 == 0) {
        factors.push_back(2);
        n /= 2;
    }

    // Step 2: Check odd numbers from 3 to sqrt(n)
    for (long long i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }

    // Step 3: If n is prime and greater than 2
    if (n > 1) {
        factors.push_back(n);
    }

    return factors;
}

int main() {
    long long N;
    cin >> N;

    vector<long long> result = primeFactorization(N);
    cout << "[";
    for (size_t i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i != result.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
