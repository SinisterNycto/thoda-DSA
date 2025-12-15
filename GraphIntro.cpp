#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m; // n nodes, m edges
    cin >> n >> m;

    // Adjacency Matrix
    // S.C: O(n * m)

    // int adj[n + 1][m + 1];

    // for(int i = 0; i < m; i++){
    //     int u, v;
    //     cin >> u >> v;
    //     adj[u][v] = 1;
    //     adj[v][u] = 1;
    // }

    // Adjacency List(for every node, stores neighbouring nodes)
    // S.C: O(2E) - every edge has two nodes(this is for undirected)
    // S.C: O(E) - for directed graph

    vector<vector<int>> adj(n + 1); // vector<int> adj[n + 1]

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) { // 1 based indexing
        cout << i << " -> ";
        for (int v : adj[i]) {
            cout << v << " ";
        }
        cout << "\n";
    }

    return 0;
}