#include <bits/stdc++.h>
using namespace std;

// Undireceted Graph
bool cycleDetect(int node, int parent, vector<vector<int>> &adj, vector<bool> &visited)
{
    visited[node] = true;
    for (int neighbor : adj[node])
    {
        if (neighbor == parent)
            continue;
        if (visited[neighbor])
            return true;
        if (cycleDetect(neighbor, node, adj, visited))
            return true;
    }
    return false;
}
bool isCycle(int V, vector<vector<int>> &edges)
{
    vector<vector<int>> adj(V);
    for (auto &edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u); // undirected graph
    }

    vector<bool> visited(V, false);
    for (int i = 0; i < V; i++)
    {
        if (!visited[i] && cycleDetect(i, -1, adj, visited))
        {
            return true;
        }
    }
    return false;
}
int main()
{
    int V = 5;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 1}}; // Contains a cycle

    bool hasCycle = isCycle(V, edges);
    cout << (hasCycle ? "Cycle detected" : "No cycle") << endl;

    return 0;
}