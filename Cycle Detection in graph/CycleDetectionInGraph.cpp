#include <iostream>
#include <list>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

bool isCyclicBFS(int src, unordered_map<int, bool> &visited,
                 unordered_map<int, list<int>> &adj)
{
    unordered_map<int, int> parent;
    parent[src] = -1;
    visited[src] = true;
    queue<int> q;
    q.push(src);
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        for (auto nbr : adj[front])
        {
            if (visited[nbr] == true && nbr != parent[front])
            {
                return true;
            }
            else if (!visited[nbr])
            {
                q.push(nbr);
                visited[nbr] = 1;
                parent[nbr] = front;
            }
        }
    }
    return false;
}

bool isCyclicDFS(int node, unordered_map<int, bool> &visited,
                 unordered_map<int, bool> &dfsvisited,
                 unordered_map<int, list<int>> &adj)
{
    visited[node] = true;
    dfsvisited[node] = true;
    for (auto neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            bool cycle = isCyclicDFS(neighbour, visited, dfsvisited, adj);
            if (cycle)
            {
                return true;
            }
        }
        else if (dfsvisited[neighbour])
        {
            return true;
        }
    }
    dfsvisited[node] = false;
    return false;
}

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].push_back(v);
    }
    // to handle disconnected component
    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsvisited;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            bool cycleFound = isCyclicDFS(n, visited, dfsvisited, adj);
            if (cycleFound == true)
            {
                return true;
            }
        }
    }
    return false;
}

string cycleDetection(vector<vector<int>> &edges, int n, int m)
{
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // to handle disconnected component
    unordered_map<int, bool> visited;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            bool ans = isCyclicBFS(i, visited, adj);
            if (ans == true)
            {
                return "Yes";
            }
        }
    }
    return "No";
}

int main()
{
    vector<int> values;
    std::vector<std::vector<int>> edges = {
        {0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 1}, {2, 4}
        // Replace these values with your edge connections
    };
    vector<pair<int, int>> edges1 = {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 1}, {2, 4}};
    string s = cycleDetection(edges, 5, 6);
    bool a = detectCycleInDirectedGraph(5, edges1);
    cout << s << endl;
    cout << a << endl;
}