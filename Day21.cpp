////Reverse a stack using recursion
#include <iostream>
#include <stack>
using namespace std;

// Function to insert an element at the bottom of the stack
void insertAtBottom(stack<int>& st, int x) {
    if (st.empty()) {
        st.push(x);
        return;
    }
    int top = st.top();
    st.pop();
    insertAtBottom(st, x);
    st.push(top);
}

// Function to reverse the stack using recursion
void reverseStack(stack<int>& st) {
    if (!st.empty()) {
        int top = st.top();
        st.pop();
        reverseStack(st);
        insertAtBottom(st, top);
    }
}

// Print stack without modifying it
void printStack(stack<int> st) {
    cout << "[Top -> Bottom]: ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int main() {
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    cout << "Original stack ";
    printStack(st);

    reverseStack(st);

    cout << "Reversed stack ";
    printStack(st);

    return 0;
}
