/*
You are given a weighted undirected graph having n vertices numbered from 1 to n
and m edges along with their weights. Find the shortest weight path between the
vertex 1 and the vertex n,  if there exists a path, and return a list of
integers whose first element is the weight of the path, and the rest consist of
the nodes on that path. If no path exists, then return a list containing a
single element -1.

The input list of edges is as follows - {a, b, w}, denoting there is an edge
between a and b, and w is the weight of that edge.

^Note: The driver code here will first check if the weight of the path returned
is equal to the sum of the weights along the nodes on that path, if equal it
will output the weight of the path, else -2. In case the list contains only a
single element (-1) it will simply output -1.

*Input: n = 5, m= 6, edges = [[1, 2, 2], [2, 5, 5], [2, 3, 4], [1, 4, 1], [4, 3,
3], [3, 5, 1]] Output: 5 Explanation: Shortest path from 1 to n is by the path 1
4 3 5 whose weight is 5.

*Constraint:
2 <= n <= 106
0 <= m <= 106
1 <= a, b <= n
1 <= w <= 105
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
  // Build adjacecncy list
  // neighbour, weight
  vector<pair<int, int>> adj[n + 1];
  for (int i = 0; i < m; i++) {
    int u = edges[i][0];
    int v = edges[i][1];
    int weight = edges[i][2];

    adj[u].push_back({v, weight});
    adj[v].push_back({u, weight});
  }

  // Dijkstra Algorithm
  vector<bool> explored(n + 1, false);
  vector<int> dist(n + 1, INT_MAX);
  vector<int> parent(n + 1, -1);

  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      p;
  p.push({0, 1});
  dist[1] = 0;
  while (!p.empty()) {
    int node = p.top().second;
    p.pop();
    if (explored[node]) continue;
    explored[node] = true;
    for (int j = 0; j < adj[node].size(); j++) {
      int neighbour = adj[node][j].first;
      int weight = adj[node][j].second;
      if (!explored[neighbour] && dist[node] + weight < dist[neighbour]) {
        dist[neighbour] = dist[node] + weight;
        p.push({dist[neighbour], neighbour});
        parent[neighbour] = node;
      }
    }
  }
  vector<int> path;
  int dest = n;
  vector<int> nodes;
  // If I can't reach my destination
  if (parent[n] == -1) return {-1};

  // If I will reach my destination
  while (dest != -1) {
    nodes.push_back(dest);
    dest = parent[dest];
  }
  reverse(path.begin(), path.end());
  path.push_back(dist[n]);
  for (int node : nodes) path.push_back(node);
  return path;
}

int main() {
  int n = 5, m = 6;
  vector<vector<int>> edges = {{1, 2, 2}, {2, 5, 5}, {2, 3, 4},
                               {1, 4, 1}, {4, 3, 3}, {3, 5, 1}};
  vector<int> ans = shortestPath(n, m, edges);

  if (ans.size() == 1 && ans[0] == -1) {
    cout << -1 << endl;
    return 0;
  }
  int reported_weight = ans[0];
  int sum = 0;

  for (int i = 1; i + 1 < ans.size(); ++i) {
    int u = ans[i], v = ans[i + 1];
    // Find the edge weight between u and v
    bool found = false;
    for (auto& e : edges) {
      if ((e[0] == u && e[1] == v) || (e[0] == v && e[1] == u)) {
        sum += e[2];
        found = true;
        break;
      }
    }
    if (!found) {
      cout << -2 << endl;
      return 0;
    }
  }

  if (sum == reported_weight) {
    cout << reported_weight << endl;
  } else {
    cout << -2 << endl;
  }

  return 0;
}