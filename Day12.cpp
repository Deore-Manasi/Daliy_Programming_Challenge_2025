//// Valid Parentheses
#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isValid(string s) {
    stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);  // Push opening brackets
        } 
        else {
            if (st.empty()) return false;  // No matching opening
            char top = st.top();
            st.pop();
            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')) {
                return false;  // Mismatch
            }
        }
    }
    return st.empty();  // Valid only if no unmatched brackets
}

int main() {
    // Test Cases
    string test1 = "()";
    string test2 = "([)]";
    string test3 = "[{()}]";
    string test4 = "";
    string test5 = "{[}";

    cout << boolalpha; // Print true/false
    cout << "Test 1: " << isValid(test1) << endl; // true
    cout << "Test 2: " << isValid(test2) << endl; // false
    cout << "Test 3: " << isValid(test3) << endl; // true
    cout << "Test 4: " << isValid(test4) << endl; // true
    cout << "Test 5: " << isValid(test5) << endl; // false

    return 0;
}
