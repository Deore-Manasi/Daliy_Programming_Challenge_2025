//// Problem: Reverse Words in a String

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

string reverseWords(string s) {
    stringstream ss(s);
    string word;
    vector<string> words;

    // Step 1: Extract words (ignores extra spaces automatically)
    while (ss >> word) {
        words.push_back(word);
    }

    // Step 2: Reverse words
    reverse(words.begin(), words.end());

    // Step 3: Join back into a string
    string result = "";
    for (int i = 0; i < words.size(); i++) {
        result += words[i];
        if (i != words.size() - 1) result += " ";
    }
    return result;
}

int main() {
    string s = "  hello   world  ";
    cout << "\"" << reverseWords(s) << "\"";  // Output: "world hello"
}
