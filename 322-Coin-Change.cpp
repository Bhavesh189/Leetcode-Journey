class Solution {
public:

    long long solve(vector<int>& coins, int t, int a, int i, vector<vector<long long>>& dp) {
        if (a > t)
            return INT_MAX;
        if (a == t)
            return 0;
        if (i < 0)
            return INT_MAX;

        if(dp[i][a] != -1) return dp[i][a];

        long long take = 1 + solve(coins, t, a + coins[i], i, dp);
        long long dontTake = INT_MAX;
        if (i != 0)
            dontTake = solve(coins, t, a, i - 1, dp);

        return dp[i][a] = min(take, dontTake);
    }

    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        vector<vector<long long>> dp(coins.size(), vector<long long>(amount+1, -1));
        long long ans = solve(coins, amount, 0, coins.size()-1, dp);

        if(ans == INT_MAX) return -1;
        else return ans;
    }
};