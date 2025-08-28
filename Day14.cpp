////Count of substrings with exactly k distinct characters
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

// Function to count substrings with at most k distinct characters
int atMostKDistinct(const string &s, int k) {
    if (k == 0) return 0;
    
    unordered_map<char, int> freq;
    int left = 0, count = 0;
    
    for (int right = 0; right < s.size(); right++) {
        freq[s[right]]++;
        
        while (freq.size() > k) { // shrink window
            freq[s[left]]--;
            if (freq[s[left]] == 0) freq.erase(s[left]);
            left++;
        }
        
        count += (right - left + 1); // all substrings ending at right
    }
    return count;
}

int substrCountExactlyK(const string &s, int k) {
    return atMostKDistinct(s, k) - atMostKDistinct(s, k - 1);
}

int main() {
    cout << substrCountExactlyK("pqpqs", 2) << endl;       // 7
    
    return 0;
}
