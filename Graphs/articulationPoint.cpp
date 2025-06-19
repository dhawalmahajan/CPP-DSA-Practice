/*
Given an undirected connected graph with V vertices and adjacency list adj. You
are required to find all the vertices removing which (and edges through it)
disconnects the graph into 2 or more components and return it in sorted manner.
Note: Indexing is zero-based i.e nodes numbering from (0 to V-1). There might be
loops present in the graph.

Your Task:
You don't need to read or print anything. Your task is to complete the function
articulationPoints() which takes V and adj as input parameters and returns a
list containing all the vertices removing which turn the graph into two or more
disconnected components in sorted order. If there are no such vertices then
returns a list containing -1.


Expected Time Complexity: O(V + E)
Expected Auxiliary Space: O(V)


Constraints:
1 ≤ V ≤ 105
*/
#include <bits/stdc++.h>
using namespace std;
void DFS(int node, int parent, vector<int> adj[], vector<bool> &visited,
         vector<int> &disc, vector<int> &low, vector<bool> &articulationPoints,
         int timer) {
  visited[node] = true;
  disc[node] = low[node] = timer;
  int child = 0;
  for (int j = 0; j < adj[node].size(); j++) {
    int neighbour = adj[node][j];
    if (neighbour == parent)
      continue;
    else if (visited[neighbour]) {
      low[node] = min(low[node], disc[neighbour]);
    } else {
      child++;
      timer++;
      DFS(neighbour, node, adj, visited, disc, low, articulationPoints, timer);
      if (disc[node] <= low[neighbour] && parent != -1) {
        articulationPoints[node] = true;
      }
      low[node] = min(low[node], low[neighbour]);
    }
  }
  if (child > 1 && parent == -1) {
    articulationPoints[node] = true;
  }
}
vector<int> articulationPoints(int V, vector<int> adj[]) {
  vector<bool> articulationPoints(V, false);
  vector<int> disc(V);
  vector<int> low(V);
  vector<bool> visited(V, false);
  int timer = 0;
  DFS(0, -1, adj, visited, disc, low, articulationPoints, timer);
  vector<int> ans;
  for (int i = 0; i < V; i++)
    if (articulationPoints[i]) ans.push_back(i);
  if (ans.size() == 0) ans.push_back(-1);
  return ans;
}

int main() {
  int V, E;
  cout << "Enter number of vertices and edges: ";
  cin >> V >> E;
  vector<int> adj[V];
  cout << endl << "Enter edges (u v):" << endl;
  for (int i = 0; i < E; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int> result = articulationPoints(V, adj);

  cout << "Articulation Points: ";
  for (int point : result) {
    cout << point << " ";
  }
  cout << endl;

  return 0;
}