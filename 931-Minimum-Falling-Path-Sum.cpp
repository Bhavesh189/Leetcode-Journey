class Solution {
public:

    int solve(vector<vector<int>>& nums, int i, int j, int m, int n, vector<vector<int>>& dp) {
        if(i<0 || j<0 || i>=m || j>=n) return INT_MAX-10000;

        if(i==m-1) return nums[i][j];

        if(dp[i][j] != INT_MIN) return dp[i][j];

        int ld = nums[i][j] + solve(nums, i+1, j-1, m, n, dp);
        int rd = nums[i][j] + solve(nums, i+1, j+1, m, n, dp);
        int dd = nums[i][j] + solve(nums, i+1, j, m, n, dp);

        return dp[i][j] = min({ld, rd, dd});
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n, INT_MIN));
        int ans = INT_MAX;

        for(int i = 0; i < n; i++) {
            ans = min(ans, solve(matrix, 0, i, m, n, dp));
        }

        return ans;
    }
};