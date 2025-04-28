#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath(vector<vector<int>> &adj, int src) {
  vector<int> dist(adj.size(), -1);
  vector<bool> visited(adj.size(), false);
  queue<int> q;
  q.push(src);
  dist[src] = 0;
  visited[src] = true;
  while (!q.empty()) {
    int node = q.front();
    q.pop();
    // Look at all the neighbours
    for (int j = 0; j < adj[node].size(); j++) {
      int neighbour = adj[node][j];
      if (!visited[neighbour]) {
        visited[neighbour] = true;
        dist[neighbour] = dist[node] + 1;
        q.push(neighbour);
      }
    }
  }
  return dist;
}
void makeGraph() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);  // For undirected graph
  }
  int src;
  cin >> src;
  vector<int> dist = shortestPath(adj, src);
  for (int i = 0; i < n; i++) {
    if (dist[i] == INT_MAX)
      cout << "Distance from " << src << " to " << i << " is " << dist[i]
           << endl;
  }
}
void createStaticInput() {
  vector<vector<int>> adj = {
      {1, 3},        // Node 0 is connected to nodes 1 and 3
      {0, 2},        // Node 1 is connected to nodes 0 and 2
      {1, 6},        // Node 2 is connected to nodes 1 and 6
      {0, 4},        // Node 3 is connected to nodes 0 and 4
      {3, 5},        // Node 4 is connected to nodes 3 and 5
      {4, 6},        // Node 5 is connected to nodes 4 and 6
      {2, 5, 7, 8},  // Node 6 is connected to nodes 2, 5, 7, and 8
      {6, 8},        // Node 7 is connected to nodes 6 and 8
      {7, 6}         // Node 8 is connected to nodes 7 and 6
  };

  int src = 0;  // Source vertex

  // Call the shortestPath function
  vector<int> dist = shortestPath(adj, src);

  // Print the distances
  for (int i = 0; i < adj.size(); i++) {
    cout << "Distance from " << src << " to " << i << " is " << dist[i] << endl;
  }
}
int main() {
  makeGraph();

  return 0;
}