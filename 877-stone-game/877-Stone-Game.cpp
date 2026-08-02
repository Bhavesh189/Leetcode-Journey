class Solution {
public:

    int solve(vector<int>& nums, int i, int j) {
        if(i > j) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int l = nums[i] - solve(nums, i+1, j);
        int r = nums[j] - solve(nums, i, j-1);

        return dp[i][j] = max(l, r);
    }

    int dp[501][501];

    bool stoneGame(vector<int>& piles) {
        memset(dp, -1, sizeof(dp));
        int n = piles.size();
        return solve(piles, 0, n-1) >= 0;
    }
};