#include<bits/stdc++.h>
using namespace std;

// 'u' is a node 'from', 'v' is a node 'to': from u to v
void add_edge_list(vector<vector<int>> &g, int u, int v) {
    g[u].push_back(v);      
    // g[v].push_back(u);      // Delete this line if graph is directed
}

void add_edge_matrix(vector<vector<int>> &g, int u, int v) {
    g[u][v] = 1;
    // g[v][u] = 1;            // Delete this line for directed graph
}

// Two functions to perform the DFS

// LIST
void topo_sort_list_visit(vector<vector<int>> &g, int start, bool* visited, stack<int> &s){
    visited[start] = true;

    for (auto v: g[start]) {
        if (!visited[v])
            topo_sort_list_visit(g, v, visited, s);
    }

    s.push(start);
}

void topo_sort_list(vector<vector<int>> &g) {
    cout << "Topo LIST:\n";

    int n = g.size();
    bool* visited = new bool[n]();
    stack<int> s;

    for (int i = 1; i < n; i++) {
        if (!visited[i])
            topo_sort_list_visit(g, i, visited, s);
    }

    // Print the stack
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

// MATRIX
void topo_sort_matrix_visit(vector<vector<int>> &g, int start, bool* visited, stack<int> &s) {
    visited[start] = true;

    for (int v = 1; v < g.size(); v++) {
        if (g[start][v] == 1 && !visited[v])
            topo_sort_matrix_visit(g, v, visited, s);
    }

    s.push(start);
}

void topo_sort_matrix(vector<vector<int>> &g) {
    cout << "Topo MATRIX:\n";

    int n = g.size();
    bool* visited = new bool[n]();
    stack<int> s;

    // This for loop is only beneficial when your graph is disconnected
    for (int i = 1; i < n; i++) {
        if (!visited[i])
            topo_sort_matrix_visit(g, i, visited, s);
    }

    // If connected, you can do it in single call:
    // dfs_matrix_visit(g, 2, visited);

    // Print the stack
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
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

    topo_sort_list(adj_list);
    topo_sort_matrix(adj_matrix);

    return 0;
}