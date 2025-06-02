/*
Given a weighted, undirected, and connected graph with V vertices and E edges,
your task is to find the sum of the weights of the edges in the Minimum Spanning
Tree (MST) of the graph. The graph is represented by an adjacency list, where
each element adj[i] is a vector containing vector of integers. Each vector
represents an edge, with the first integer denoting the endpoint of the edge and
the second integer denoting the weight of the edge.

^Input:
3 3
0 1 5
1 2 3
0 2 1

^Output: 4

^Constraints:
2 ≤ V ≤ 1000
V-1 ≤ E ≤ (V*(V-1))/2
1 ≤ w ≤ 1000
The graph is connected and doesn't contain self-loops & multiple edges.
*/

#include <bits/stdc++.h>
using namespace std;

int spanningTree(int V, vector<vector<int>> adj[]) {
  priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                 greater<pair<int, pair<int, int>>>>
      pq;
  vector<bool> isMst(V, false);
  vector<int> parent(V);
  int cost = 0;
  pq.push({0, {0, -1}});
  while (!pq.empty()) {
    int weight = pq.top().first;
    int node = pq.top().second.first;
    int par = pq.top().second.second;
    pq.pop();
    if (!isMst[node]) {
      isMst[node] = true;
      cost += weight;
      parent[node] = par;
      for (int j = 0; j < adj[node].size(); j++) {
        int nextnode = adj[node][j][0];
        int nextweight = adj[node][j][1];
        if (!isMst[nextnode]) {
          pq.push({nextweight, {nextnode, node}});
        }
      }
    }
  }
  return cost;
}
int main() {
  int V, E;
  cin >> V >> E;
  vector<vector<int>> adj[V];
  for (int i = 0; i < E; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }
  cout << spanningTree(V, adj) << endl;
  return 0;
}