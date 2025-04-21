#include <bits/stdc++.h>
using namespace std;
// undirected unWeighted graph
void undirectedGrapth()
{
    int vertex, edges;
    cin >> vertex >> edges;
    vector<int> adjacencyList[vertex];
    int u, v;
    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v;
        adjacencyList[u].push_back(v);
        adjacencyList[v].push_back(u);
    }
    for (int i = 0; i < vertex; i++)
    {
        cout << i << " -> ";
        for (int j = 0; j < adjacencyList[i].size(); j++)
        {
            cout << adjacencyList[i][j] << " ";
        }
        cout << endl;
    }
}
// undirected weighted graph
void weightedGrapth()
{
    int vertex, edges;
    cin >> vertex >> edges;
    vector<pair<int, int>> adjacencyList[vertex];
    int u, v, weight;
    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v >> weight;
        adjacencyList[u].push_back(make_pair(v, weight));
        adjacencyList[v].push_back(make_pair(u, weight));
    }
    for (int i = 0; i < vertex; i++)
    {
        cout << i << " -> ";
        for (int j = 0; j < adjacencyList[i].size(); j++)
        {
            cout << adjacencyList[i][j].first << " " << adjacencyList[i][j].second << " ";
        }
        cout << endl;
    }
}

int main()
{
    // undirectedGrapth();
    weightedGrapth();
    return 0;
}