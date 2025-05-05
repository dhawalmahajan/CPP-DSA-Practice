#include <bits/stdc++.h>
using namespace std;

bool isBipartite(int V, vector<vector<int>> &edges) {
  // Code here
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
