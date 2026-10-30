class Solution {
public:
    int solve(string& t1, string& t2, int i, int j, vector<vector<int>>& dp) {
        if(i<0 || j<0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(t1[i]==t2[j]) return 1 + solve(t1, t2, i-1, j-1, dp);
        else {
            int ans = 0;

            int take = solve(t1, t2, i-1, j, dp);
            int dontTake = solve(t1, t2, i, j-1, dp);

            return dp[i][j] = max(take, dontTake);
        }
    }


    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        return solve(text1, text2, m-1, n-1, dp);
    }
};