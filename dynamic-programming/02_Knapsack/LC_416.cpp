class Solution {
public:
    int memo[201][20001];

    bool subset_sum(vector<int> &nums, int n, int sum) {
        if (n == -1)     // no more items left
            return 0;

        if (sum == 0)    // leftover sum is found.
            return 1;

        // Recall step
        if (memo[n][sum] != -1)
            return memo[n][sum];

        if (nums[n] > sum) {
            memo[n][sum] = subset_sum(nums, n-1, sum);
        } else {
            memo[n][sum] = subset_sum(nums, n-1, sum) || subset_sum(nums, n-1, sum-nums[n]);
        }

        return memo[n][sum];
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto x: nums) 
            sum += x;

        // Initialize it to -1
        for (int i = 0; i <= nums.size(); i++)
            for (int j = 0; j <= sum; j++)
                memo[i][j] = -1;

        if (sum%2 != 0)
            return false;
        else
            return subset_sum(nums, nums.size() - 1, sum/2);
    }
};