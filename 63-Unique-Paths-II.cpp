class Solution {
public:

    int solve(vector<vector<int>>& nums, int i, int j, int m, int n, vector<vector<int>>& dp) {
        if(i<0 || j<0 || i>=m || j>=n) return 0;
        if(nums[i][j] == 1) return dp[i][j] = 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(i==m-1 && j==n-1) return dp[i][j] = 1;
        else return dp[i][j] = solve(nums, i+1, j, m, n, dp) + solve(nums, i, j+1, m, n, dp);
    }

    int uniquePathsWithObstacles(vector<vector<int>>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(nums[0].size(), -1));
        return solve(nums, 0, 0, nums.size(), nums[0].size(), dp);
    }
};