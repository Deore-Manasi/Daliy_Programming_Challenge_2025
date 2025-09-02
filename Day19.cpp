////Evaluate the value of an arithmetic expression in Reverse Polish Notation.
#include <iostream>
#include <stack>
#include <sstream>
#include <string>
using namespace std;

int evaluatePostfix(const string &expr) {
    stack<long long> st;  // use long long for safety
    stringstream ss(expr);
    string token;

    while (ss >> token) {
        // If it's a number
        if (!(token == "+" || token == "-" || token == "*" || token == "/")) {
            st.push(stoll(token)); // convert to long long
        } 
        else {
            // Pop top two elements
            long long b = st.top(); st.pop();
            long long a = st.top(); st.pop();
            long long res;

            if (token == "+") res = a + b;
            else if (token == "-") res = a - b;
            else if (token == "*") res = a * b;
            else if (token == "/") res = a / b; // truncates toward zero

            st.push(res);
        }
    }

    return (int)st.top();
}

int main() {
    string expr;
    expr = "2 1 + 3 *";  // Example input
    //getline(cin, expr);  
    cout << evaluatePostfix(expr) << endl;
    return 0;
}
