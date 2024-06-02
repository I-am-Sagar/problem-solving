class Solution {
public:
    int memo[13][10001];

    int knapsack(vector<int> &coins, int n, int amount) {
        if (amount == 0)
            return 0;
        
        if (n == coins.size()) 
            return INT_MAX-1;

        if (memo[n][amount] != -1)
            return memo[n][amount];

        // You can always skip
        int skip_coin = knapsack(coins, n+1, amount);

        // You can only pick if amount > coins[n]
        int take_coin = INT_MAX-1;
        if (amount >= coins[n]) {
            take_coin = 1 + knapsack(coins, n, amount - coins[n]);
        }

        memo[n][amount] = min(skip_coin, take_coin);
        return memo[n][amount];
    }

    int coinChange(vector<int>& coins, int amount) {
        
        for (int i = 0; i <= coins.size(); i++)
            for (int j = 0; j <= amount; j++)
                memo[i][j] = -1;

        int ans = knapsack(coins, 0, amount);

        if (ans == INT_MAX-1)
            return -1;
        
        return ans;
        
    }
};