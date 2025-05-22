/*
Given a Directed Acyclic Graph of V vertices from 0 to n-1 and a 2D Integer
array(or vector) edges[ ][ ] of length E, where there is a directed edge from
edge[i][0] to edge[i][1] with a distance of edge[i][2] for all i.

Find the shortest path from src(0) vertex to all the vertices and if it is
impossible to reach any vertex, then return -1 for that vertex.


Input: V = 4, E = 2, edges = [[0,1,2], [0,2,1]]
Output: [0, 2, 1, -1]
Explanation: Shortest path from 0 to 1 is 0->1 with edge weight 2. Shortest path
from 0 to 2 is 0->2 with edge weight 1. There is no way we can reach 3, so it's
-1 for 3.

^Constraint:
1 <= V <= 100
1 <= E <= min((N*(N-1))/2,4000)
0 <= edgesi,0, edgesi,1 < n
0 <= edgei,2 <=105

Time Complexity: O(V + E)
Space Complexity: O(V + E)
Where V is the number of vertices and E is the number of edges in the graph.
*/
#include <bits/stdc++.h>
using namespace std;
void DFS(int node, vector<pair<int, int>> adj[], stack<int>& s1,
         vector<bool>& visited) {
  visited[node] = true;
  // look at all its neighbours
  for (int j = 0; j < adj[node].size(); j++) {
    int neighbour = adj[node][j].first;
    if (!visited[neighbour]) {
      DFS(neighbour, adj, s1, visited);
    }
    s1.push(node);
  }
}

vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
  // create adjacency list

  vector<pair<int, int>> adj[V];
  for (int i = 0; i < E; i++) {
    int u = edges[i][0];
    int v = edges[i][1];
    int weight = edges[i][2];
    adj[u].push_back(make_pair(v, weight));
  }
  // Topological sort using DFS
  stack<int> s1;
  vector<bool> visited(V, 0);
  DFS(0, adj, s1, visited);
  vector<int> dist(V, INT_MAX);
  dist[0] = 0;

  // Empty the stack
  while (!s1.empty()) {
    int node = s1.top();
    s1.pop();
    // look at all its neighbours
    for (int j = 0; j < adj[node].size(); j++) {
      int neighbour = adj[node][j].first;
      int weight = adj[node][j].second;
      dist[neighbour] = min(dist[neighbour], weight + dist[node]);
    }
  }

  // replace all INT_MAX with -1
  for (int i = 0; i < V; i++) {
    if (dist[i] == INT_MAX) dist[i] = -1;
  }
  return dist;
}

int main() {
  int V = 4, E = 2;
  vector<vector<int>> edges = {{0, 1, 2}, {0, 2, 1}};
  vector<int> result = shortestPath(V, E, edges);
  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << " ";
  }
  return 0;
}