/*
You are given an weighted directed graph, represented by an adjacency matrix,
dist[][] of size n x n, where dist[i][j] represents the weight of the edge from
node i to node j. If there is no direct edge, dist[i][j] is set to a large value
(i.e., 108) to represent infinity. The graph may contain negative edge weights,
but it does not contain any negative weight cycles.

Your task is to find the shortest distance between every pair of nodes i and j
in the graph.

&Note: Modify the distances for every pair in place.

!Input:
 dist[][] = [[0, 4, 108, 5, 108], [108, 0, 1, 108, 6], [2, 108, 0, 3,
108], [108, 108, 1, 0, 2], [1, 108, 108, 4, 0]]

!Output:
 [[0, 4, 5, 5, 7], [3, 0, 1, 4, 6], [2, 6, 0, 3, 5], [3, 7, 1, 0, 2],[1,
5, 5, 4, 0]]

^Constraints:
1 ≤ dist.size() ≤ 100
-1000 ≤ dist[i][j] ≤ 1000
dist[i][j] can be 108 to represent infinity.
*/
#include <bits/stdc++.h>
using namespace std;

void floydWarshall(vector<vector<int>> &dist) {
  int n = dist.size();
  const int INF = 100000000;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (dist[i][j] >= INF)
        dist[i][j] = INF;  // Set to a large value to represent infinity

  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (dist[i][k] == INF || dist[k][j] == INF)
          continue;  // Skip if there's no path through k
        if (dist[i][j] > dist[i][k] + dist[k][j])
          dist[i][j] = dist[i][k] + dist[k][j];
        // dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (dist[i][j] >= INF) dist[i][j] = INF;
}

int main() {
  vector<vector<int>> dist = {{0, 4, 108, 5, 108},
                              {108, 0, 1, 108, 6},
                              {2, 108, 0, 3, 108},
                              {108, 108, 1, 0, 2},
                              {1, 108, 108, 4, 0}};

  floydWarshall(dist);

  for (const auto &row : dist) {
    for (int val : row) {
      cout << (val >= 100000000 ? "INF" : to_string(val)) << " ";
    }
    cout << endl;
  }
}