class Solution {
public:
    int knapsack(const vector<int>& coins, int amount, int index, vector<vector<int>>& memo) {
        // Base cases
        if (amount == 0) {
            return 1;
        }
        if (amount < 0 || index < 0) {
            return 0;
        }
        
        // Check memoization table
        if (memo[index][amount] != -1) {
            return memo[index][amount];
        }
        
        // Calculate the number of ways by including the current coin and excluding it
        int include = knapsack(coins, amount - coins[index], index, memo);
        int exclude = knapsack(coins, amount, index - 1, memo);
        
        // Store the result in the memoization table
        memo[index][amount] = include + exclude;
        
        return memo[index][amount];
    }

    int change(int amount, vector<int>& coins) {
        // Initialize the memoization table with -1
        vector<vector<int>> memo(coins.size(), vector<int>(amount + 1, -1));
        return knapsack(coins, amount, coins.size() - 1, memo);
    }
};
