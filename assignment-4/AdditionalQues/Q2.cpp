#include <iostream>
#include <queue>
#include<climits>
using namespace std;

// Function to get the index of minimum element in the first "n" elements
int minIndex(queue<int>& q, int sortedIndex) {
    int min_index = -1;
    int min_val = INT_MAX;
    int n = q.size();

    for (int i = 0; i < n; i++) {
        int curr = q.front();
        q.pop();

        // Only check unsorted part
        if (i <= sortedIndex && curr <= min_val) {
            min_index = i;
            min_val = curr;
        }

        q.push(curr); // keep queue same
    }
    return min_index;
}

// Move element at min_index to the rear
void insertMinToRear(queue<int>& q, int min_index) {
    int min_val;
    int n = q.size();

    for (int i = 0; i < n; i++) {
        int curr = q.front();
        q.pop();

        if (i == min_index) {
            min_val = curr; // store min
        } else {
            q.push(curr); // keep other elements
        }
    }
    q.push(min_val); // put min at rear
}

// Sort function
void sortQueue(queue<int>& q) {
    int n = q.size();
    for (int i = 1; i <= n; i++) {
        int min_index = minIndex(q, n - i);
        insertMinToRear(q, min_index);
    }
}

int main() {
    queue<int> q;
    q.push(11);
    q.push(5);
    q.push(4);
    q.push(21);

    sortQueue(q);

    cout << "Sorted Queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}
