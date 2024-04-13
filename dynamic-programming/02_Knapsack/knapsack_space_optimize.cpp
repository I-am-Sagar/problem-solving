#include <bits/stdc++.h>
using namespace std;

int memo[1001];  // max(C) = 1000.

int knapsack(int n, int C, vector<int> price, vector<int> weight) {

    memo[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int w = C; w >= 0; w--) {
            if (weight[i-1] <= w)
                memo[w] = max(memo[w], memo[w-weight[i-1]] + price[i-1]);
        }
    }
    
    return memo[C];
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

    // NO NEED TO INITIALIZE -1 IN CASE OF TABULATION

    // for (int i = 0; i <= n; i++) {
    //     for (int j = 0; j <= C; j++) {
    //         memo[i][j] = -1;
    //     }
    // }

    // Notice that we are passing here n and not n-1.
    cout << knapsack(n, C, price, weight) << endl;

    return 0;
}
