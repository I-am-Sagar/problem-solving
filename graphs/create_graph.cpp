#include<bits/stdc++.h>
using namespace std;

// 'u' is a node 'from', 'v' is a node 'to': from u to v
void add_edge_list(vector<vector<int>> &g, int u, int v) {
    g[u].push_back(v);      
    g[v].push_back(u);      // Delete this line if graph is directed
}

void add_edge_matrix(vector<vector<int>> &g, int u, int v) {
    g[u][v] = 1;
    g[v][u] = 1;            // Delete this line for directed graph
}

// Two helper functions to print the graphs
void print_graph_list(vector<vector<int>> g) {
    cout << "ADJ LIST:\n";
    for (int i = 0; i < g.size(); i++) {
        cout << i << ": ";
        for (auto v: g[i]) {
            cout << v << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void print_graph_matrix(vector<vector<int>> g) {
    cout << "ADJ MATRIX:\n";
    cout << "  ";
    for (int i = 0; i < g.size(); i++) {
        cout << " " << i;
    }
    cout << endl;

    for (int i = 0; i < g.size(); i++) {
        cout << i << ": ";
        for (int j = 0; j < g[i].size(); j++) {
            cout << g[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {

    int n, e; cin >> n >> e;

    // Adjacency list
    vector<vector<int>> adj_list(n, vector<int>());

    // Adjacency matrix
    vector<vector<int>> adj_matrix(n, vector<int>(n, 0));   // nxn matrix all zeros

    // Our nodes are from 0 to n-1
    while (e--) {
        int u, v; cin >> u >> v;
        add_edge_list(adj_list, u, v);
        add_edge_matrix(adj_matrix, u, v);
    }

    print_graph_list(adj_list);
    print_graph_matrix(adj_matrix);

    return 0;
}