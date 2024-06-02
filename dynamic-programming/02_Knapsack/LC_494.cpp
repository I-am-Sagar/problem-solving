class Solution {
public:
    int knapsack(vector<int> &arr, int n, int target) {
        if (n == arr.size()) {
            if (target == 0)
                return 1;
            return 0;
        }

        int pick = knapsack(arr, n+1, target + arr[n]);
        int skip = knapsack(arr, n+1, target - arr[n]);

        return pick + skip;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return knapsack(nums, 0, target);
    }
};