#include <bits/stdc++.h>
using namespace std;

int memo[1001][1001];  // max(n) = 1000, max(C) = 1000.

int knapsack(int n, int C, vector<int> price, vector<int> weight) {
    if (n == -1 || C <= 0)
        return 0;

    if (memo[n][C] != -1)
        return memo[n][C];

    int ans = INT_MIN;
    // Only choice to skip
    if (weight[n] > C)
        ans = knapsack(n-1, C, price, weight);
    else // Else, max of skip and pick
        ans = max(knapsack(n-1, C, price, weight), price[n] + knapsack(n-1, C-weight[n], price, weight)); 
    
    memo[n][C] = ans;
    return memo[n][C];
}

int main() {

    int n, C; cin >> n >> C;

    vector<int> price, weight; 

    int temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        price.push_back(temp);
    }

    for (int i = 0; i < n; i++) {
        cin >> temp;
        weight.push_back(temp);
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= C; j++) {
            memo[i][j] = -1;
        }
    }

    cout << knapsack(n-1, C, price, weight) << endl;

    return 0;
}

/*

In the tabulation method, bottom up, we can space-optimize to 1D memo table and not 2D. 

*/