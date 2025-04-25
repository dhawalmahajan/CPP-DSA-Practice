#include <bits/stdc++.h>
using namespace std;

// bfs traversal using kahn's algorithm
vector<int> topoSort(int V, vector<vector<int>> &edges)
{
    vector<vector<int>> adj(V);
    for (auto &edge : edges)
    {
        adj[edge[0]].push_back(edge[1]);
    }
    vector<int> inDegree(V, 0); // store indegree of each node
    vector<int> ans;
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            inDegree[adj[i][j]]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        if (!inDegree[i])
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for (int j = 0; j < adj[node].size(); j++)
        {
            inDegree[adj[node][j]]--;
            if (inDegree[adj[node][j]] == 0)
            {
                q.push(adj[node][j]);
            }
        }
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
    return 0;
}