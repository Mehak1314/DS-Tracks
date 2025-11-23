#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph
{
public:
    vector<vector<int>> adj;

    Graph(int n)
    {
        adj.resize(n);
    }

    void addEdge(int u, int v, bool directed)
    {
        adj[u].push_back(v);
        if (!directed)
            adj[v].push_back(u);
    }

    void print()
    {
        for (int i = 0; i < adj.size(); i++)
        {
            cout << i << ": ";
            for (int x : adj[i])
                cout << x << " ";
            cout << endl;
        }
    }

    void bfs(int start)
    {
        vector<int> visited(adj.size(), 0);
        queue<int> q;

        visited[start] = 1;
        q.push(start);

        cout << "BFS: ";

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            cout << node << " ";

            for (int next : adj[node])
            {
                if (!visited[next])
                {
                    visited[next] = 1;
                    q.push(next);
                }
            }
        }
        cout << endl;
    }
};

int main()
{
    int nodes, edges;
    cout << "Enter number of nodes: ";
    cin >> nodes;

    Graph g(nodes);

    cout << "Enter number of edges: ";
    cin >> edges;

    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, false);
    }

    g.print();

    int start;
    cout << "Enter start node for BFS: ";
    cin >> start;

    g.bfs(start);

    return 0;
}
