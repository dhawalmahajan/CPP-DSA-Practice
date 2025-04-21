#include <bits/stdc++.h>
using namespace std;

// Adjacency Matrix Representation of Graph
// undirected weighted graph
int main()
{
    int vertex, edge;

    cout << "Enter number of vertices: ";
    cin >> vertex >> edge;
    vector<vector<int>> adjMatrix(vertex, vector<int>(vertex, 0));
    int u, v, weight;
    for (int i = 0; i < edge; i++)
    {
        cin >> u >> v >> weight;
        adjMatrix[u][v] = weight;
        adjMatrix[v][u] = weight;
    }
    cout << endl;
    for (int i = 0; i < vertex; i++)
    {
        for (int j = 0; j < vertex; j++)
            cout << adjMatrix[i][j] << " ";
        cout << endl;
    }
}