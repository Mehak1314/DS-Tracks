#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int parent[1000];
int rankv[1000];
int findparent(int node)
{
    if (parent[node] == node)
        return node;
    return parent[node] = findparent(parent[node]);
}

void unionSet(int u, int v)
{
    u = findparent(u);
    v = findparent(v);

    if (u == v)
        return; 

    if (rankv[u] < rankv[v])
    {
        parent[u] = v;
    }
    else if (rankv[u] > rankv[v])
    {
        parent[v] = u;
    }
    else
    {
        parent[v] = u;
        rankv[u]++; 
    }
}

int main()
{
    int V, E;
    cout << "ENTER NUMBER OF VERTICES: ";
    cin >> V;
    cout << "ENTER NUMBER OF EDGES: ";
    cin >> E;
    vector<pair<int, pair<int, int>>> edges;

    cout << "ENTER EDGES AS: u v w\n";
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, {u, v}});
    }

    for (int i = 0; i < V; i++)
    {
        parent[i] = i;
        rankv[i] = 0;
    }

    sort(edges.begin(), edges.end());

    int totalWeight = 0;
    vector<pair<int, pair<int, int>>> mst;
    for (auto &e : edges)
    {
        int w = e.first;
        int u = e.second.first;
        int v = e.second.second;
        if (findparent(u) != findparent(v))
        {
            unionSet(u, v);
            mst.push_back(e);
            totalWeight += w;
        }
    }

    cout << "\nMST EDGES:\n";
    for (auto &e : mst)
    {
        cout << e.second.first << " - " << e.second.second
             << "  weight = " << e.first << "\n";
    }

    cout << "TOTAL MST WEIGHT = " << totalWeight << endl;

    return 0;
}
