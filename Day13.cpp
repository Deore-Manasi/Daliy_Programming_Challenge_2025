////Longest Palindromic Substring

#include <iostream>
#include <string>
using namespace std;


int expandFromCenter(const string &s, int left, int right) {
    while (left >= 0 && right < s.length() && s[left] == s[right]) {
        left--;
        right++;
    }
    return right - left - 1; // length of palindrome
}

string longestPalindrome(string s) {
    if (s.length() < 2) return s;

    int start = 0, maxLen = 1;
    for (int i = 0; i < s.length(); i++) {
        // Odd length palindrome
        int len1 = expandFromCenter(s, i, i);
        // Even length palindrome
        int len2 = expandFromCenter(s, i, i + 1);

        int len = max(len1, len2);
        if (len > maxLen) {
            maxLen = len;
            start = i - (len - 1) / 2; 
        }
    }
    return s.substr(start, maxLen);
}

int main() {
    // Test cases
    cout << longestPalindrome("babad") << endl; // bab
    
    return 0;
}
