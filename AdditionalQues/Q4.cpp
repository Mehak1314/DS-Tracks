#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        stack<int> s; // store indices

        for (int i = n - 1; i >= 0; i--) {
            // pop until we find a warmer day
            while (!s.empty() && temperatures[s.top()] <= temperatures[i]) {
                s.pop();
            }

            if (!s.empty()) {
                ans[i] = s.top() - i; // distance to next warmer day
            }

            s.push(i); // push current index
        }

        return ans;
    }
};
