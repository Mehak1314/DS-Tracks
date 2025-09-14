#include <iostream>
#include <queue>
using namespace std;

void generateBinary(int n) {
    queue<string> q;
    q.push("1"); // Start with "1"

    for (int i = 1; i <= n; i++) {
        string curr = q.front();
        q.pop();
        cout << curr << " ";  // Print current binary number

        // Append "0" and "1" to generate next numbers
        q.push(curr + "0");
        q.push(curr + "1");
    }
}

int main() {
    int n = 2;
    generateBinary(n);
    return 0;
}
