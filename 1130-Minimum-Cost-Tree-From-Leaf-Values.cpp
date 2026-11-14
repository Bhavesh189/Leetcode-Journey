class Solution {
public:

    int solve(vector<int>& arr, int l, int r, vector<vector<int>>& dp) {
        if(l==r) return 0;
        if(dp[l][r] != -1) return dp[l][r];
        int ans = INT_MAX/1000;

        for(int k = l; k < r; k++) {
            int lmax, rmax;
            lmax = rmax = INT_MIN;

            for(int i = k+1; i <= r; i++) rmax = max(rmax, arr[i]);
            for(int i = k; i >= l; i--) lmax = max(lmax, arr[i]);
            int temp = solve(arr, l, k, dp) + solve(arr, k+1, r, dp) + (lmax*rmax);
            ans = min(ans, temp);
        }

        return dp[l][r] = ans;
    }

    int mctFromLeafValues(vector<int>& arr) {
        int rm = 1, lm = 1;
        int n = arr.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        return solve(arr, 0, n-1, dp);
    }
};