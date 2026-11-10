class Solution {
public:
    int solve(vector<int>& nums, int i, vector<int>& dp, int n) {
        if (i == n)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int m = INT_MAX;

        for (int j = 1; (j < 4) && (i + j <= n); j++) {
            m = min(m, nums[i + j - 1] + (j * j) + solve(nums, i + j, dp, n));
        }

        return dp[i] = m;
    }

    int climbStairs(int n, vector<int>& costs) {
        int ans = INT_MAX;
        vector<int> dp(n+1, -1);

        return solve(costs, 0, dp, n);
    }
};