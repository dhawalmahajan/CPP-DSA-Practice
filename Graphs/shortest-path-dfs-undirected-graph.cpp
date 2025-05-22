
/*
The city of Ninjaland is analogous to the unweighted graph. The city has ‘N’
houses numbered from 1 to ‘N’ respectively and are connected by M bidirectional
roads. If a road is connecting two houses ‘X’ and ‘Y’ which means you can go
from ‘X’ to ‘Y’ or ‘Y’ to ‘X’. It is guaranteed that you can reach any house
from any other house via some combination of roads. Two houses are directly
connected by at max one road.

A path between house ‘S’ to house ‘T’ is defined as a sequence of vertices from
‘S’ to ‘T’. Where starting house is ‘S’ and the ending house is ‘T’ and there is
a road connecting two consecutive houses. Basically, the path looks like this:
(S , h1 , h2 , h3 , ... T). you have to find the shortest path from ‘S’ to ‘T’.

Constraints :
1 <= T <= 100
2 <= N <= 10 ^ 3
1 <= M <= min( N *(N - 1) / 2 , 1000 )
1 <= S, T <= N

Sample input 1 :
1
4 4
1 4
1 2
2 3
3 4
1 3
Sample Output 1 :
( 1 , 3 , 4 )
*/
#include <bits/stdc++.h>
using namespace std;
vector<int> shortestPath(vector<pair<int, int>> edges, int N, int M, int src,
                         int dest) {
  vector<int> adj[N];
  for (int i = 0; i < M; i++) {
    adj[edges[i].first - 1].push_back(edges[i].second - 1);
    adj[edges[i].second - 1].push_back(edges[i].first - 1);
  }
  src--;
  dest--;

  vector<int> dist(N, -1);
  vector<bool> visited(N, false);
  queue<int> q;
  q.push(src);
  dist[src] = 0;
  visited[src] = true;
  vector<int> parent(N, -1);

  while (!q.empty()) {
    int node = q.front();
    q.pop();
    // Look at all the neighbours
    for (int j = 0; j < adj[node].size(); j++) {
      int neighbour = adj[node][j];
      if (!visited[neighbour]) {
        visited[neighbour] = true;
        dist[neighbour] = dist[node] + 1;
        q.push(neighbour);
        parent[neighbour] = node;
      }
    }
  }
  vector<int> path;
  while (dest != -1) {
    path.push_back(dest + 1);
    dest = parent[dest];
  }
  reverse(path.begin(), path.end());
  return path;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; i++) {
      cin >> edges[i].first >> edges[i].second;
    }
    int src, dest;
    cin >> src >> dest;
    vector<int> ans = shortestPath(edges, n, m, src, dest);
    if (ans.size() == 0) {
      cout << -1 << endl;
    } else {
      cout << "( ";
      for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];
        if (i != ans.size() - 1) {
          cout << " , ";
        }
      }
      cout << " )" << endl;
    }
  }
  return 0;
  // Time Complexity: O(N + M)
  // Space Complexity: O(N + M)
  // N = number of nodes
  // M = number of edges
  // The space complexity is O(N + M) because we are using an adjacency list
  // to represent the graph, which takes O(N + M) space. The visited array
  // takes O(N) space, and the parent array takes O(N) space. The queue
  // takes O(N) space in the worst case. So the total space complexity is
  // O(N + M) + O(N) + O(N) + O(N) = O(N + M).
}