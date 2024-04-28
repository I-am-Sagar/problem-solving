#include<bits/stdc++.h>
using namespace std;

// 'u' is a node 'from', 'v' is a node 'to': from u to v
void add_edge_list(vector<vector<int>> &g, int u, int v) {
    g[u].push_back(v);      
    // g[v].push_back(u);      // Delete this line if graph is directed
}

void add_edge_list_undirected(vector<vector<int>> &g, int u, int v) {
    g[u].push_back(v);      
    g[v].push_back(u);      // Delete this line if graph is directed
}

// Check if the undirected graph has a cycle. DFS
bool has_cycle_visit(vector<vector<int>> &g, int u, bool* visited, int parent) {
    visited[u] = true;
    for (auto v: g[u]) {
        if (!visited[v]) 
            return has_cycle_visit(g, v, visited, u);
        else if (v != parent)
            return true;
    }
    return false;
}

bool has_cycle(vector<vector<int>> &g) {
    int n = g.size();
    bool* visited = new bool[n]();
    for (int i = 0; i < n; i++) {
        if (!visited[i]) 
            return has_cycle_visit(g, i, visited, -1);
    }
    return false;
}

// Check if the directed graph has a cycle. DFS
bool has_cycle_visit_directed(vector<vector<int>> g, int u, bool* visited, bool* recursion_stack) {
    if (!visited[u]) {
        visited[u] = true;
        recursion_stack[u] = true;

        for (auto v: g[u]) {
            if (!visited[v] && has_cycle_visit_directed(g, v, visited, recursion_stack))
                return true;
            else if (recursion_stack[v])
                return true;
        }

        recursion_stack[u] = false;
        return false;
    }
}

bool has_cycle_directed(vector<vector<int>> &g) {
    int n = g.size();

    bool* visited = new bool[n]();
    bool* recursion_stack = new bool[n]();

    for (int i = 0; i < n; i++) {
        return has_cycle_visit_directed(g, i, visited, recursion_stack);
    }

    return false;
}

int main() {
    int n, e; cin >> n >> e;

    // Adjacency list
    vector<vector<int>> adj_list(n, vector<int>());
    vector<vector<int>> adj_list2(n, vector<int>());

    // Our nodes are from 0 to n-1
    while (e--) {
        int u, v; cin >> u >> v;
        add_edge_list(adj_list, u, v);
        add_edge_list_undirected(adj_list2, u, v);
    }

    if (has_cycle_directed(adj_list))
        cout << "Has cycle.\n"; 
    else 
        cout << "Doesn't have cycle.\n";

    if (has_cycle(adj_list2)) 
        cout << "Has cycle.\n";
    else   
        cout << "Doesn't have cycle.\n";

    return 0;
}