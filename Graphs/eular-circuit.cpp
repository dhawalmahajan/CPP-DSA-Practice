/*
An Eulerian Path is a path in graph that visits every edge exactly once. An
Eulerian Circuit is an Eulerian Path which starts and ends on the same vertex.
Given an undirected connected graph with V nodes, and E edges, with adjacency
list adj, return 2 if the graph contains an eulerian circuit, else if the graph
contains an eulerian path, return 1, otherwise, return 0.

Your Task:
You don't need to read or print anything. Your task is to complete the function
isEulerCircuilt() which takes number of vertices in the graph denoted as V and
an adjacency list of graph denoted as adj and returns 2 if the graph contains an
eulerian circuit, else if the graph contains an eulerian path, it returns 1,
otherwise, it will return 0.

Expected Time Complexity: O(V+E) where E is the number of edges in graph.
Expected Space Complexity: O(V)

Constraints:
1 ≤ V, E ≤ 104
1 ≤ adj[i][j] ≤ V-1
*/
#include <bits/stdc++.h>
using namespace std;
void DFS(int node, vector<int> adj[], vector<bool> &visited) {
  visited[node] = true;
  for (int j = 0; j < adj[node].size(); j++) {
    int neighbour = adj[node][j];
    if (!visited[neighbour]) {
      DFS(neighbour, adj, visited);
    }
  }
}
int isEulerCircuit(int V, vector<int> adj[]) {
  // Eular Circuit: 2
  // Calculate degree of each vertex
  // All node should have even degree for Eulerian Circuit
  // All 0 degree nodes should be connected to each other
  // Eular Path: 1
  // Calculate degree of each vertex
  // 0 or 2 nodes can have odd degree and remaining have even degree
  // All Non 0 degree nodes should be connected to each other
  vector<int> degree(V, 0);
  int oddDegree = 0;
  for (int i = 0; i < V; i++) {
    degree[i] = adj[i].size();
    if (degree[i] % 2) oddDegree++;
  }
  if (oddDegree != 2 && oddDegree != 0) return 0;

  vector<bool> visited(V, false);
  for (int i = 0; i < V; i++) {
    if (degree[i]) {
      DFS(i, adj, visited);
      break;  // Start DFS from the first non-zero degree node
    }
  }
  // If non zero degree node is still not visited, return 0
  for (int i = 0; i < V; i++) {
    if (degree[i] && !visited[i]) return 0;
  }
  if (oddDegree == 0) {
    return 2;
  } else {
    return 1;
  }
}

int main() {
  int V = 5;
  vector<int> adj[V];
  adj[0] = {1, 2};
  adj[1] = {0, 2, 3};
  adj[2] = {0, 1, 3, 4};
  adj[3] = {1, 2};
  adj[4] = {2};

  int result = isEulerCircuit(V, adj);
  cout << "Result: " << result << endl;  // Output: Result: 1 (Eulerian Path)

  return 0;
}