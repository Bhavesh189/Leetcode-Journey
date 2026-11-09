class Solution {
public:

    int solve(string& s, int i, int j, vector<vector<int>>& dp) {
        if(i>=j) return true;

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == s[j] && solve(s, i+1, j-1, dp)) return dp[i][j] = true;
        else return dp[i][j] = false;
    }

    int minCut(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                dp[i][j] = solve(s, i, j, dp);
            }
        }

        vector<int> cuts(n, INT_MAX);

        for(int i = n-1; i >= 0; i--) {
            for(int j = i; j < n; j++) {
                if(dp[i][j]) {
                    if(j==n-1) cuts[i] = 0;
                    else cuts[i] = min(cuts[i], 1 + cuts[j+1]);
                }
            }
        }

        return cuts[0];
    }
};