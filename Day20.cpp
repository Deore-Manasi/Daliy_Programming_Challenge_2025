////Sort a stack using recursion
#include <iostream>
#include <stack>
using namespace std;

void insertSorted(stack<int>& st, int x) {
    if (st.empty() || st.top() <= x) {
        st.push(x);
        return;
    }
    int top = st.top();
    st.pop();
    insertSorted(st, x);
    st.push(top);
}

void sortStack(stack<int>& st) {
    if (!st.empty()) {
        int top = st.top();
        st.pop();
        sortStack(st);
        insertSorted(st, top);
    }
}

// Print without destroying stack
void printStack(stack<int> st) {
    cout << "Stack (top to bottom): ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int main() {
    stack<int> st;
    st.push(3);
    st.push(1);
    st.push(4);
    st.push(2);

    cout << "Original ";
    printStack(st);  // This prints a copy, so stack remains intact

    sortStack(st);

    cout << "Sorted ";
    printStack(st);

    return 0;
}
