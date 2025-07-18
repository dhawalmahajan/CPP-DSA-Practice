#include <algorithm>
#include <iostream>
#include <list>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> shortestPathUndirectedGraph(vector<pair<int, int>> edges, int n,
                                        int m, int s, int t) {
  // creta adjacency list
  unordered_map<int, list<int>> adj;
  for (int i = 0; i < edges.size(); i++) {
    int u = edges[i].first;
    int v = edges[i].second;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  // do bfs
  unordered_map<int, bool> visited;
  unordered_map<int, int> parent;
  queue<int> q;
  q.push(s);
  parent[s] = -1;
  visited[s] = true;

  while (!q.empty()) {
    int frontNode = q.front();
    q.pop();
    for (auto i : adj[frontNode]) {
      visited[i] = true;
      parent[i] = frontNode;
      q.push(i);
    }
  }

  // prepare shortest path
  vector<int> ans;
  int curr = t;
  ans.push_back(t);
  while (curr != s) {
    curr = parent[curr];
    ans.push_back(curr);
  }

  reverse(ans.begin(), ans.end());
  return ans;
}

std::vector<std::pair<int, int>> createEdges() {
  std::vector<std::pair<int, int>> edges;

  // Adding static values to the vector of pairs
  edges.push_back(std::make_pair(1, 2));
  edges.push_back(std::make_pair(3, 4));
  edges.push_back(std::make_pair(5, 6));

  return edges;
}
int main() {
  std::vector<std::pair<int, int>> edges = createEdges();
  for (const auto &ed : edges) {
    std::cout << ed.first << " -> " << ed.second << std::endl;
  }

  vector<int> ans = shortestPathUndirectedGraph(edges, 6, 6, 1, 6);
  for (const auto edge : ans) {
    std::cout << edge;
  }
}
