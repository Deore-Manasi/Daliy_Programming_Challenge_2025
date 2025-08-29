////longest unique substring
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int lengthOfLongestSubstring(string s) {
    vector<int> lastIndex(256, -1); // Store last seen index of characters
    int maxLen = 0, left = 0;

    for (int right = 0; right < s.size(); right++) {
        // If the character was seen and is inside the current window
        if (lastIndex[s[right]] >= left) {
            left = lastIndex[s[right]] + 1; // Move left pointer
        }
        lastIndex[s[right]] = right; // Update last seen index
        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}

int main() {
    cout << lengthOfLongestSubstring("abcabcbb") << endl; // 3
    cout << lengthOfLongestSubstring("abcdefgh") << endl; // 8
    cout << lengthOfLongestSubstring("a") << endl;        // 1
    return 0;
}
