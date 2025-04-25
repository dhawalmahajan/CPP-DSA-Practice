#include <bits/stdc++.h>
using namespace std;

void DFS(int node, vector<vector<int>> &adj, vector<bool> &visited, vector<int> &ans)
{
    visited[node] = 1;
    ans.push_back(node);
    for (int j = 0; j < adj[node].size(); j++)
    {
        if (!visited[adj[node][j]])
        {
            DFS(adj[node][j], adj, visited, ans);
        }
    }
}
vector<int> dfs(vector<vector<int>> &adj)
{
    // Code here
    vector<bool> visited(adj.size(), 0);
    vector<int> ans;
    DFS(0, adj, visited, ans);
    return ans;
}
int main()
{
    vector<vector<int>> adj = {
        {1, 2},
        {0, 3},
        {0, 4},
        {1},
        {2}};
    vector<int> result = dfs(adj);
    for (int i : result)
    {
        cout << i << " ";
    }
    return 0;
}