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

// Two functions to perform the BFS

// LIST
void bfs_list(vector<vector<int>> &g, int start) {
    cout << "BFS LIST:\n";

    int n = g.size();
    bool* visited = new bool[n]();
    int* level = new int[n]();
    int* parent = new int[n]();
    queue<int> q;
    int i = 1;
    
    // process the start node
    q.push(start);
    visited[start] = true;
    level[start] = i-1;
    parent[start] = -1;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        cout << u << " ";      // Printing: Anything with the node, should be done here.
        for (auto v: g[u]) {
            // Anything with the edge, should be done here.
            if (!visited[v]) {
                q.push(v);
                visited[v] = true;
                level[v] = i;
                parent[v] = u;
            }
        }
        i++;
    }

    cout << endl << endl;

    for (int i = 0; i < n; i++)
        cout << i << " ";
    cout << endl;

    for (int i = 0; i < n; i++) {
        cout << level[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < n; i++) {
        cout << parent[i] << " ";
    }
    cout << endl;

    // Shortest path logic
    int dest = 2; vector<int> path;
    while (dest != -1) {
        path.push_back(dest);
        dest = parent[dest];
    }
    reverse(path.begin(), path.end());

    for (auto x: path)
        cout << x << " ";
    cout << endl;
}

// MATRIX
void bfs_matrix(vector<vector<int>> &g, int start) {
    cout << "BFS MATRIX:\n";

    int n = g.size();
    bool* visited = new bool[n]();
    int* level = new int[n]();
    int* parent = new int[n]();
    queue<int> q;
    int i = 1;
    
    // process the start node
    q.push(start);
    visited[start] = true;
    level[start] = i-1;
    parent[start] = -1;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        cout << u << " ";
        for (int v = 0; v < n; v++) {
            if (g[u][v] == 1 && !visited[v]) {
                q.push(v);
                visited[v] = true;
                level[v] = i;
                parent[v] = u;
            }
        }
        i++;
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

    // Note: If you have a disconnected graph, go for DFS. Try to avoid BFS.
    bfs_list(adj_list, 0);
    bfs_matrix(adj_matrix, 0);

    return 0;
}