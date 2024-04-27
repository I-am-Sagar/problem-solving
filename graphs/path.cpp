// PS: Given src node and dest node, give me a path between them

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

// GET PATH CODES

bool get_path_list_dfs_rec(vector<vector<int>> &g, int src, int dest, vector<int> &path) {
    static bool* visited = new bool[g.size()](); 
    
    path.push_back(src);
    visited[src] = true;

    if (src == dest)
        return true;

    for (auto v: g[src]) {
        if (!visited[v]) {
            if (get_path_list_dfs_rec(g, v, dest, path))
                return true;
        }
    }

    path.pop_back();
    return false;
}

void get_path_list_dfs_itr(vector<vector<int>> &g, int src, int dest, vector<int> &path) {
    int n = g.size();
    bool* visited = new bool[n]();

    stack<int> s;
    s.push(src);
    visited[src] = true;

    while (!s.empty()) {
        int u = s.top();
        s.pop();
        path.push_back(u);

        if (u == dest) // If destination reached, break out of the loop
            break;

        bool found = false; // Flag to indicate if a neighbor leads to destination
        for (auto v : g[u]) {
            if (!visited[v]) {
                s.push(v);
                visited[v] = true;
                found = true;
                break; // Break after pushing the first unvisited neighbor
            }
        }

        if (!found) {
            path.pop_back(); // Remove the last node from path if no unvisited neighbor leads to destination
        }
    }    
}


void get_path_list_bfs(vector<vector<int>> &g, int src, int dest, vector<int> &path) {
    int n = g.size();
    bool* visited = new bool[n]();
    int* level = new int[n]();
    int* parent = new int[n]();
    queue<int> q;
    int i = 1;
    
    // process the start node
    q.push(src);
    visited[src] = true;
    level[src] = i-1;
    parent[src] = -1;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        // cout << u << " ";
        for (auto v: g[u]) {
            if (!visited[v]) {
                q.push(v);
                visited[v] = true;
                level[v] = i;
                parent[v] = u;
            }
        }
        i++;
    }
    // cout << endl;

    // To get the path, we will use parent array
    while (dest != -1) {
        path.push_back(dest);
        dest = parent[dest];
    }

    reverse(path.begin(), path.end());
}

void get_path_matrix_dfs(vector<vector<int>> &g, int src, int dest, vector<int> &path) {
    int n = g.size();
    bool* visited = new bool[n]();

    stack<int> s;
    s.push(src);
    visited[src] = true;

    while (!s.empty()) {
        int u = s.top();
        s.pop();
        path.push_back(u);

        if (u == dest) // If destination reached, break out of the loop
            break;

        bool found = false; // Flag to indicate if a neighbor leads to destination
        for (int v = 0; v < n; v++) {
            if (g[u][v] == 1 && !visited[v]) {
                s.push(v);
                visited[v] = true;
                found = true;
                break; // Break after pushing the first unvisited neighbor
            }
        }

        if (!found) {
            path.pop_back(); // Remove the last node from path if no unvisited neighbor leads to destination
        }
    }    
}

void get_path_matrix_bfs(vector<vector<int>> &g, int src, int dest, vector<int> &path) {
    int n = g.size();
    bool* visited = new bool[n]();
    int* level = new int[n]();
    int* parent = new int[n]();
    queue<int> q;
    int i = 1;
    
    // process the start node
    q.push(src);
    visited[src] = true;
    level[src] = i-1;
    parent[src] = -1;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        // cout << u << " ";
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
    // cout << endl;

    // To get the path, we will use parent array
    while (dest != -1) {
        path.push_back(dest);
        dest = parent[dest];
    }

    reverse(path.begin(), path.end());
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

    vector<int> path_1, path_2, path_3, path_4, path_5;
    get_path_list_dfs_rec(adj_list, 2, 5, path_1);
    get_path_list_dfs_itr(adj_list, 2, 5, path_2);
    get_path_list_bfs(adj_list, 2, 5, path_3);

    for (auto x: path_1)
        cout << x << " ";
    cout << endl;

    for (auto x: path_2)
        cout << x << " ";
    cout << endl;

    for (auto x: path_3)
        cout << x << " ";
    cout << endl;

    get_path_matrix_dfs(adj_matrix, 2, 5, path_4);
    get_path_matrix_bfs(adj_matrix, 2, 5, path_5);

    for (auto x: path_4)
        cout << x << " ";
    cout << endl;

    for (auto x: path_5)
        cout << x << " ";
    cout << endl;

}

// Note: List is more popular, so practice that!!