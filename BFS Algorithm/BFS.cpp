#include <iostream>
#include <list>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

void prepareAdjList(unordered_map<int, set<int>> &adjList,
                    vector<pair<int, int>> &edges)
{
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}
void bfs(unordered_map<int, set<int>> &adjList,
         unordered_map<int, bool> &visited, vector<int> &ans, int node)
{
    queue<int> q;
    q.push(node);
    visited[node] = 1;
    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();
        // store front node in ans
        ans.push_back(frontNode);
        // traverse all neighbours of frontNode

        for (auto i : adjList[frontNode])
        {
            if (!visited[i])
            {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    unordered_map<int, set<int>> adjList;
    vector<int> ans;
    unordered_map<int, bool> visited;
    prepareAdjList(adjList, edges);

    // traverse all components of graph
    for (int i = 0; i < vertex; i++)
    {
        if (!visited[i])
        {
            bfs(adjList, visited, ans, i);
        }
    }
    return ans;
}

int main()
{
    int startVertex = 0;
    std::vector<std::pair<int, int>> edges = {
        {0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 1}, {2, 4}
        // Replace these values with your edge connections
    };
    std::vector<int> traversal = BFS(startVertex, edges);
    std::cout << "BFS Traversal from vertex " << startVertex << ":\n";
    for (int vertex : traversal)
    {
        std::cout << vertex << " ";
    }
    std::cout << std::endl;
    return 0;
}