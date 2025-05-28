/*
Given an weighted graph with V vertices numbered from 0 to V-1 and E edges,
represented by a 2d array edges[][], where edges[i] = [u, v, w] represents a
direct edge from node u to v having w edge weight. You are also given a source
vertex src.

Your task is to compute the shortest distances from the source to all other
vertices. If a vertex is unreachable from the source, its distance should be
marked as 108. Additionally, if the graph contains a negative weight cycle,
return [-1] to indicate that shortest paths cannot be reliably computed.

Input: V = 5, edges[][] = [[1, 3, 2], [4, 3, -1], [2, 4, 1], [1, 2, 1], [0, 1,
5]], src = 0

Output: [0, 5, 6, 6, 7]
Explanation: Shortest Paths:
For 0 to 1 minimum distance will be 5. By following path 0 → 1
For 0 to 2 minimum distance will be 6. By following path 0 → 1  → 2
For 0 to 3 minimum distance will be 6. By following path 0 → 1  → 2 → 4 → 3
For 0 to 4 minimum distance will be 7. By following path 0 → 1  → 2 → 4

Constraints:
1 ≤ V ≤ 100
1 ≤ E = edges.size() ≤ V*(V-1)
-1000 ≤ w ≤ 1000
0 ≤ src < V

Time complexity: O(V * E)
Space complexity: O(V)
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
  vector<int> dist(V, 1e8);
  dist[src] = 0;
  int e = edges.size();
  // Relax all the edges (V-1) times
  for (int i = 0; i < V - 1; i++) {
    for (int j = 0; j < e; j++) {
      int u = edges[j][0];
      int v = edges[j][1];
      int weight = edges[j][2];
      if (dist[u] == 1e8) continue;
      if (dist[u] + weight < dist[v]) {
        dist[v] = dist[u] + weight;
      }
    }
  }
  // To detect the cycle, we will run the loop one more time

  for (int j = 0; j < e; j++) {
    int u = edges[j][0];
    int v = edges[j][1];
    int weight = edges[j][2];
    if (dist[u] == 1e8) continue;
    if (dist[u] + weight < dist[v]) {
      // Cycle detected
      vector<int> ans;
      ans.push_back(-1);
      return ans;
    }
  }
  return dist;
}

int main() {
  int V = 5;
  vector<vector<int>> edges = {
      {1, 3, 2}, {4, 3, -1}, {2, 4, 1}, {1, 2, 1}, {0, 1, 5}};
  int src = 0;

  vector<int> result = bellmanFord(V, edges, src);

  // Print the result
  for (int d : result) {
    cout << d << " ";
  }

  return 0;
}