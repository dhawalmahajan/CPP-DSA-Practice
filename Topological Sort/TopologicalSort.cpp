#include <iostream>
#include <list>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;
void topoSort(int node, unordered_map<int, list<int>> &adj, vector<bool> &vis,
              stack<int> &s)
{
    vis[node] = true;
    for (auto neighbour : adj[node])
    {
        if (!vis[neighbour])
        {
            topoSort(neighbour, adj, vis, s);
        }
    }
    s.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < e; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }
    vector<bool> visited;
    stack<int> s;
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            topoSort(i, adj, visited, s);
        }
    }
    vector<int> ans;
    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}
int main()
{
    vector<vector<int>> edges = {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}, {6, 7}, {7, 8}};
    vector<int> ans = topologicalSort(edges, 0, edges.size());
    for (auto i : ans)
    {
        cout << i << " ";
    }
}