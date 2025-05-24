/*
Given an undirected, weighted graph with V vertices numbered from 0 to V-1 and E
edges, represented by 2d array edges[][], where edges[i]=[u, v, w] represents
the edge between the nodes u and v having w edge weight. You have to find the
shortest distance of all the vertices from the source vertex src, and return an
array of integers where the ith element denotes the shortest distance between
ith node and source vertex src.

Note: The Graph is connected and doesn't contain any negative weight edge.

!Input: V = 3, edges[][] = [[0, 1, 1], [1, 2, 3], [0, 2, 6]], src = 2
!Output: [4, 3, 0]


^Constraints:
1 ≤ V ≤ 105
1 ≤ E = edges.size() ≤ 105
0 ≤ edges[i][j] ≤ 104
0 ≤ src < V
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
  // Build adjacency list
  vector<vector<pair<int, int>>> adj(V);
  for (auto &edge : edges) {
    int u = edge[0], v = edge[1], w = edge[2];
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  vector<int> dist(V, INT_MAX);
  dist[src] = 0;

  // Min-heap: {distance, node}
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  pq.push({0, src});
  while (!pq.empty()) {
    int d = pq.top().first;
    int node = pq.top().second;
    pq.pop();

    // If we already found a better path, skip
    if (d > dist[node]) continue;

    for (auto &nbr : adj[node]) {
      int v = nbr.first, w = nbr.second;
      if (dist[node] + w < dist[v]) {
        dist[v] = dist[node] + w;
        pq.push({dist[v], v});
      }
    }
  }
  return dist;
}

int main() {
  int V = 3;
  vector<vector<int>> edges = {{0, 1, 1}, {1, 2, 3}, {0, 2, 6}};
  int src = 2;
  vector<int> ans = dijkstra(V, edges, src);
  for (int d : ans) cout << d << " ";
  cout << endl;
  return 0;
}
/*
Each node is processed in O(log V) time due to the priority queue.
The overall complexity is O((V + E) log V), which is efficient for large graphs.
*/