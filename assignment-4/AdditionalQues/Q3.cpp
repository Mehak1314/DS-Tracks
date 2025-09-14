#include <iostream>
#include <queue>
#include <stack>
using namespace std;

bool checkQueue(queue<int>& q) {
    stack<int> st;
    int expected = 1;
    int n = q.size();

    while (!q.empty()) {
        int front = q.front();
        q.pop();

        if (front == expected) {
            expected++;
        }
        else {
            if (!st.empty() && st.top() < front) {
                // If stack top is smaller than current element
                // then sorting not possible
                return false;
            }
            st.push(front);
        }

        // Pop from stack if top matches expected
        while (!st.empty() && st.top() == expected) {
            st.pop();
            expected++;
        }
    }

    // Check remaining stack
    while (!st.empty() && st.top() == expected) {
        st.pop();
        expected++;
    }

    return (expected == n + 1);
}

int main() {
    queue<int> q;
    q.push(5);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    if (checkQueue(q))
        cout << "Yes";
    else
        cout << "No";

    return 0;
}
