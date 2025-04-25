#include <bits/stdc++.h>
using namespace std;

bool detectCycle(int node, vector<vector<int>> &adj, vector<bool> &path, vector<bool> &visited)
{
    visited[node] = true;
    path[node] = true;
    // look for adjacent node
    for (int j = 0; j < adj[node].size(); j++)
    {
        int neighbor = adj[node][j];
        // if node is already present in my path then cycle is present
        if (path[neighbor] == true)
            return true;
        // If neighbour already visited then ignore it
        if (!visited[neighbor] && detectCycle(neighbor, adj, path, visited))
            return true;
    }
    path[node] = false; // backtrack
    return false;
}
bool isCyclic(int V, vector<vector<int>> &edges)
{
    vector<vector<int>> adj(V);
    vector<bool> path(V, 0);
    vector<bool> visited(V, 0);
    for (auto &edge : edges)
    {
        adj[edge[0]].push_back(edge[1]);
    }
    for (int i = 0; i < V; i++)
    {
        if (!visited[i] && detectCycle(i, adj, path, visited))
            return true;
    }
    return false;
}

int main()
{
    int V = 6;
    vector<vector<int>> edges = {
        {5, 2},
        {5, 0},
        {4, 0},
        {4, 1},
        {2, 3},
        {3, 1}};

    bool result = isCyclic(V, edges);
    cout << "Cycle present: " << (result ? "Yes" : "No") << endl;

    return 0;
}
