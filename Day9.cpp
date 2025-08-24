////longest common prefix

#include <iostream>
#include <vector>
#include <string>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return "";

    // Take the first string as reference
    string prefix = strs[0];

    // Compare prefix with each string
    for (int i = 1; i < strs.size(); i++) {
        int j = 0;
        // Find common prefix between prefix and current string
        while (j < prefix.size() && j < strs[i].size() && prefix[j] == strs[i][j]) {
            j++;
        }
        prefix = prefix.substr(0, j);  // Trim prefix

        // If prefix becomes empty, return immediately
        if (prefix.empty()) return "";
    }
    return prefix;
}

int main() {
    vector<string> strs = {"flower", "flow", "flight"};
    cout << "\"" << longestCommonPrefix(strs) << "\"";  // Output: "fl"
}
