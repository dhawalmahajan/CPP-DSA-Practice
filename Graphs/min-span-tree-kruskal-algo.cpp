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

// Function to find the parent of a node in the disjoint set using path
// compression

int findParent(int u, vector<int> &parent) {
  if (u == parent[u]) return u;
  return parent[u] = findParent(parent[u], parent);
}
void unionByRank(int u, int v, vector<int> &parent, vector<int> &rank) {
  int pu = findParent(u, parent);
  int pv = findParent(v, parent);
  if (rank[pu] > rank[pv]) {
    parent[pv] = pu;
  } else if (rank[pu] < rank[pv]) {
    parent[pu] = pv;
  } else {
    parent[pv] = pu;
    rank[pu]++;
  }
}
int spanningTree(int V, vector<vector<int>> adj[]) {
  vector<int> parent(V);   // Ultimate parent will help to determine set
  vector<int> rank(V, 0);  // It will help us to merge the set
  for (int i = 0; i < V; i++) parent[i] = i;
  // wt, u, v
  priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                 greater<pair<int, pair<int, int>>>>
      pq;
  for (int i = 0; i < V; i++) {
    for (int j = 0; j < adj[i].size(); j++) {
      int weight = adj[i][j][1];
      int nextnode = adj[i][j][0];
      pq.push({weight, {i, nextnode}});
    }
  }
  int cost = 0;
  int edges = 0;
  while (!pq.empty()) {
    int weight = pq.top().first;
    int u = pq.top().second.first;
    int v = pq.top().second.second;
    pq.pop();
    // CHeck if u & v are in different sets
    if (findParent(u, parent) != findParent(v, parent)) {
      cost += weight;
      unionByRank(u, v, parent, rank);
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