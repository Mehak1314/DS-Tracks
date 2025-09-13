#include <iostream>
#include <stack>
#include <climits>
using namespace std;

class MinStack {
    stack<int> st;
    int minElement;

public:
    MinStack() { 
        minElement = INT_MAX; 
    }
    void insertValue(int x) {
        st.push(x);
        if (x < minElement) {
            minElement = x;   // keep track of current minimum
        }
    }
    int getMin() {
        if (st.empty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return minElement;
    }
};

int main() {
    MinStack ms;
    ms.insertValue(5);
    ms.insertValue(3);
    ms.insertValue(7);
    cout << "Current Min: " << ms.getMin() << endl; // 3
    return 0;
}
