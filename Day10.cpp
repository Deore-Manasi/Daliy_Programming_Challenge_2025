//// Group Anagrams
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> mp;

    for (string s : strs) {
        string key = s;
        sort(key.begin(), key.end());  // Sort to create key
        mp[key].push_back(s);
    }

    vector<vector<string>> result;
    for (auto &pair : mp) {
        result.push_back(pair.second);
    }
    return result;
}

int main() {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> groups = groupAnagrams(strs);

    for (auto group : groups) {
        cout << "[ ";
        for (auto word : group) cout << word << " ";
        cout << "]\n";
    }
}
