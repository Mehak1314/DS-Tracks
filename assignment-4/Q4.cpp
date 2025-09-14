#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

void firstNonRepeating(string str) {
    unordered_map<char, int> freq;  // store frequency of characters
    queue<char> q;                  // store characters in order of arrival

    for (char ch : str) {
        // step 1: update frequency
        freq[ch]++;

        // step 2: push into queue
        q.push(ch);

        // step 3: remove all characters from queue which are repeating
        while (!q.empty() && freq[q.front()] > 1) {
            q.pop();
        }

        // step 4: print first non-repeating
        if (q.empty()) {
            cout << -1 << " ";
        } else {
            cout << q.front() << " ";
        }
    }
    cout << endl;
}

int main() {
    string input = "aabc";  // you can take input from user also
    firstNonRepeating(input);
    return 0;
}
