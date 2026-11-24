class Solution {
public:
    bool solve(string& s, int i, int j, int n, vector<vector<int>>& dp) {
        if (i >= j)
            return true;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i] == s[j] && solve(s, i + 1, j - 1, n, dp))
            return dp[i][j] = true;
        return dp[i][j] = false;
    }

    int cuts(string& s, int i, vector<int>& memo, vector<vector<int>>& dp) {
        if (i == s.size())
            return -1;

        if(memo[i] != -1) return memo[i];
        int ans = INT_MAX;

        for (int j = i; j < s.size(); j++) {
            if (dp[i][j]) {
                int x = min(ans, cuts(s, j + 1, memo, dp));
                if(x != INT_MAX) ans = min(ans, x+1);
            }
        }

        return memo[i] = ans;
    }

    int minCut(string s) {
        int n = s.size();

        vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                dp[i][j] = solve(s, i, j, n, dp);
            }
        }

        vector<int> memo(s.size(), -1);

        return cuts(s, 0, memo, dp);
    }
};