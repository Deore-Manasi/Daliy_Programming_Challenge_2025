////Generate all unique permutations of a string with possible duplicate characters
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void backtrack(string &s, vector<bool> &used, string &current, vector<string> &result) {
    if (current.size() == s.size()) {
        result.push_back(current);
        return;
    }
    
    for (int i = 0; i < s.size(); i++) {
        // Skip used characters
        if (used[i]) continue;
        
        // Skip duplicates: if current char == previous char and previous not used
        if (i > 0 && s[i] == s[i-1] && !used[i-1]) continue;
        
        used[i] = true;
        current.push_back(s[i]);
        
        backtrack(s, used, current, result);
        
        // Backtrack
        current.pop_back();
        used[i] = false;
    }
}

vector<string> permuteUnique(string s) {
    vector<string> result;
    sort(s.begin(), s.end()); // Sort to handle duplicates
    vector<bool> used(s.size(), false);
    string current;
    
    backtrack(s, used, current, result);
    return result;
}

int main() {
    string s = "aab";
    vector<string> permutations = permuteUnique(s);
    
    for (auto &perm : permutations) {
        cout << perm << " ";
    }
    return 0;
}
