#include <bits/stdc++.h>
using namespace std;

//* DFS Approach
bool checkBipartite(int node, vector<vector<int>> &adj, vector<int> &color) {
  for (int j = 0; j < adj[node].size(); j++) {
    int neighbor = adj[node][j];
    if (color[neighbor] == -1) {
      color[neighbor] = 1 - color[node];
      if (!checkBipartite(neighbor, adj, color)) {
        return false;
      }
    } else {
      if (color[neighbor] == color[node]) {
        return false;  // Same color as the current node
      }
    }
  }
  return true;
}
bool isBipartiteUsingDFS(int V, vector<vector<int>> &edges) {
  vector<vector<int>> adj(V);
  for (auto &edge : edges) {
    int u = edge[0];
    int v = edge[1];
    adj[u].push_back(v);
    adj[v].push_back(u);  // Since the graph is undirected
  }
  vector<int> color(V, -1);
  for (int i = 0; i < V; i++) {
    if (color[i] == -1) {
      color[i] = 0;  // Start coloring with color 0
      if (!checkBipartite(i, adj, color)) {
        return false;  // If the graph is not bipartite, return false
      }
    }
  }
  return true;
}
//* BFS Approch

bool isBipartiteUsingBFS(int V, vector<vector<int>> &edges) {
  vector<vector<int>> adj(V);
  for (auto &edge : edges) {
    int u = edge[0];
    int v = edge[1];
    adj[u].push_back(v);
    adj[v].push_back(u);  // Since the graph is undirected
  }

  vector<int> color(V, -1);
  queue<int> q;
  for (int i = 0; i < V; i++) {
    if (color[i] == -1) {
      q.push(i);
      color[i] = 0;
      while (!q.empty()) {
        int node = q.front();
        q.pop();

        // Iterate over all neighbors of the current node
        for (int neighbor : adj[node]) {
          if (color[neighbor] == -1) {
            // Assign the opposite color to the neighbor
            color[neighbor] = 1 - color[node];  // (color[node] + 1) % 2;
            q.push(neighbor);
          } else if (color[neighbor] == color[node]) {
            // If the neighbor has the same color, the graph is not bipartite
            return false;
          }
        }
      }
    }
  }

  return true;
}
bool isBipartite(int V, vector<vector<int>> &edges) {
  // return isBipartiteUsingBFS(V, edges);
  return isBipartiteUsingDFS(V, edges);
  // You can also use DFS approach
}
int main() {
  int V, E;
  cin >> V >> E;
  vector<vector<int>> edges(V);
  for (int i = 0; i < E; i++) {
    int u, v;
    cin >> u >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
  if (isBipartite(V, edges)) {
    cout << "1 (Graph is Bipartite)" << endl;
  } else {
    cout << "0 (Graph is not Bipartite)" << endl;
  }
  return 0;
}
