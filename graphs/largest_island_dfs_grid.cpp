/*  PROBLEM:

    Given a 2D square matrix of size N that contains 0s and 1s. 1 represents land
    and 0 represents water. Two lands with 1s belong to same island, if
    they share an edge with each other. Find the size of the largest island.

    Input:
    Line 1 : An integer N denoting the size of graph
    Next N lines : N characters denoting the graph

    Output:
    Size of the biggest piece of '1's and no '0's

    Constraints:
    1 <= N <= 50
*/

#include <bits/stdc++.h>
using namespace std;
#define MAX 51   // constraints

// Main Logic of Code  (DFSVisit)
int dfs (char graph[MAX][MAX], int n, bool** visited, int i, int j, int count) {
    visited[i][j] = true;

    if (i > 0 && graph[i-1][j] == '1' && !visited[i-1][j])
        count = dfs (graph, n, visited, i-1, j, count) + 1;
    if (j < n-1 && graph[i][j+1] == '1' && !visited[i][j+1])
        count = dfs (graph, n, visited, i, j+1, count) + 1;
    if (i < n-1 && graph[i+1][j] == '1' && !visited[i+1][j])
        count = dfs (graph, n, visited, i+1, j, count) + 1;
    if (j > 0 && graph[i][j-1] == '1' && !visited[i][j-1])
        count = dfs (graph, n, visited, i, j-1, count) + 1;

    return count;
}

// DFS
int largestIsland(char graph[MAX][MAX], int n) {
    bool** visited = new bool*[n];
    for (int i = 0; i < n; i++)
        visited[i] =  new bool[n]();

    int max = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (!visited[i][j] && graph[i][j] == '1') {
                int count = 0;
                int n = dfs(graph, n, visited, i, j, count) + 1;
                if (n > max)
                    max = n;
            }
            for (int k = 0; k < n; k++)
                for (int m = 0; m < n; m++)
                    visited[k][m] = false;
        }
    return max;
}

/* -------------- MAIN DRIVER CODE --------------- */
int main() {
    char graph[MAX][MAX];
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
        scanf("%s", graph[i]);

    cout << largestIsland(graph, n) << endl;
    return 0;
}