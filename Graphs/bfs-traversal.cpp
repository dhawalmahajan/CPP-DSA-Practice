#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(vector<vector<int>> &adj) {
  // Code here
  queue<int> q;
  q.push(0);
  vector<int> ans;
  vector<bool> visited(adj.size(), 0);
  visited[0] = 1;
  int node;
  while (!q.empty()) {
    node = q.front();
    q.pop();
    ans.push_back(node);
    for (int j = 0; j < adj[node].size(); j++) {
      if (!visited[adj[node][j]]) {
        visited[adj[node][j]] = 1;
        q.push(adj[node][j]);
      }
    }
  }
  return ans;
}
int main() {
  vector<vector<int>> adj = {{1, 2}, {0, 3}, {0, 4}, {1}, {2}};
  vector<int> result = bfs(adj);
  for (int i : result) {
    cout << i << " ";
  }
  return 0;
}