#include <bits/stdc++.h>
using namespace std;
void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited, stack<int> &s)
{
    visited[node] = true;
    for (int neighbor : adj[node])
    {
        if (!visited[neighbor])
        {
            dfs(neighbor, adj, visited, s);
        }
    }
    s.push(node);
}
vector<int> topoSort(int V, vector<vector<int>> &edges)
{
    // code here
    vector<vector<int>> adj(V);
    for (auto &edge : edges)
    {
        adj[edge[0]].push_back(edge[1]);
    }

    vector<bool> visited(V, false);
    stack<int> s;
    vector<int> ans;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            dfs(i, adj, visited, s);
        }
    }

    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }

    return ans;
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

    vector<int> result = topoSort(V, edges);
    cout << "Topological Sort: ";
    for (int i : result)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}