#include<bits/stdc++.h>
using namespace std;

class Edge {
    public:
        int src, dest, weight;
};

bool compare(Edge e1, Edge e2) {
    return e1.weight < e2.weight;
}

int root(int v, int* parent) {
    if (parent[v] == v)
        return v;
    return root(parent[v], parent);
}

Edge* kruskal(Edge* edges, int n, int e) {
    Edge* output = new Edge[n-1];

    // Sort the edges
    sort(edges, edges + e, compare);

    // We need to have a parent array (for maintaining DSU)
    int* parent = new int[n];
    for (int i = 0; i < n; i++)
        parent[i] = i;

    int count = 0, i = 0;  // to break the loop when I have picked n-1 edges
    while (count < n-1) {
        Edge current_edge = edges[i];

        int src_parent = root(current_edge.src, parent);
        int dest_parent = root(current_edge.dest, parent);
        
        if (src_parent != dest_parent) {
            output[count] = current_edge;
            parent[src_parent] = dest_parent;
            count++;
        }

        i++;
    }

    return output;
}

int main() {

    int n, e; cin >> n >> e;

    Edge* edges = new Edge[e];
    for (int i = 0; i < e; i++) {
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
    }

    cout << "Edges in MST:\n";

    Edge* output = kruskal(edges, n, e);

    for (int i = 0; i < n-1; i++) {
        cout << output[i].src << " " << output[i].dest << " " << output[i].weight << endl;
    }

    return 0;
}