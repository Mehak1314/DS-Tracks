#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Depth-First Search function to mark all reachable nodes
    void dfs(int node, vector<vector<int>>& adj, vector<int>& visited) {
        visited[node] = 1;  // mark current node as visited

        for (int neighbor : adj[node]) {   // explore all connected nodes
            if (!visited[neighbor]) {      // if neighbor is not visited
                dfs(neighbor, adj, visited);
            }
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        // Step 1: Build adjacency list
        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]); // undirected graph
        }

        vector<int> visited(n, 0);
        int components = 0;

        // Step 2: Run DFS from each unvisited node
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {     // found a new component
                components++;
                dfs(i, adj, visited);
            }
        }

        return components;
    }
};

int main() {
    int V = 5;
    vector<vector<int>> edges = {{0,1}, {1,2}, {3,4}};

    Solution s;
    cout << s.countComponents(V, edges);
    return 0;
}
