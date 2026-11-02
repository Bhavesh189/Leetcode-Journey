class Solution {
public:

    #define ll long long

    ll solve(vector<vector<int>>& nums, int i, int j, int m, int n, vector<vector<ll>>& dp) {
        if(i<0 || j<0 || i>=m || j>=n) return INT_MAX;
        if(dp[i][j] != -1) return dp[i][j];
        if(i==m-1 && j==n-1) return dp[i][j] = nums[i][j];

        ll r = solve(nums, i, j+1, m, n, dp);
        ll b = solve(nums, i+1, j, m, n, dp);

        return dp[i][j] = nums[i][j] + min(b, r);
    }

    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<ll>> dp(grid.size(), vector<ll>(grid[0].size(), -1));
        return solve(grid, 0, 0, grid.size(), grid[0].size(), dp);
    }
};