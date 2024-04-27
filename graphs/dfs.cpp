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

// Two functions to perform the DFS

// LIST
void dfs_list_visit(vector<vector<int>> &g, int start, bool* visited){
    stack <int> s;
    
    s.push(start);
    visited[start] = true;

    while (!s.empty()) {
        int u = s.top(); s.pop();
        cout << u << " ";
        for (auto v: g[u]) {
            if (!visited[v]) {
                s.push(v);
                visited[v] = true;
            }
        }
    }
    cout << endl;
}

void dfs_list(vector<vector<int>> &g) {
    cout << "DFS LIST:\n";

    int n = g.size();
    bool* visited = new bool[n]();

    for (int i = 0; i < n; i++) {
        if (!visited[i])
            dfs_list_visit(g, i, visited);
    }
}

// MATRIX
void dfs_matrix_visit(vector<vector<int>> &g, int start, bool* visited) {
    stack<int> s;

    s.push(start);
    visited[start] = true;

    while (!s.empty()) {
        int u = s.top(); s.pop();
        cout << u << " ";

        for (int v = 0; v < g.size(); v++) {
            // if (start == v)
            //     continue;
            if (g[u][v] == 1 && !visited[v]) {
                s.push(v);
                visited[v] = true;
            }
        }
    }

    cout << endl;
}

void dfs_matrix(vector<vector<int>> &g) {
    cout << "DFS MATRIX:\n";

    int n = g.size();
    bool* visited = new bool[n]();

    // This for loop is only beneficial when your graph is disconnected
    for (int i = 0; i < n; i++) {
        if (!visited[i])
            dfs_matrix_visit(g, i, visited);
    }

    // If connected, you can do it in single call:
    // dfs_matrix_visit(g, 2, visited);
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

    dfs_list(adj_list);
    dfs_matrix(adj_matrix);

    return 0;
}