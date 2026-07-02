class Solution {
public:

    bool solve(vector<int>& nums, int k, int i) {
        if(i == nums.size()-1) return dp[k][i] = true;

        if(dp[k][i] != -1) return dp[k][i];

        int m = k-1, n = k, o = k+1;
        int arr[3] = {m, n, o};
        
        for(int x = 0; x < 3; x++) {
            int j = nums[i] + arr[x];
            bool z = false;
            if(arr[x] > 0 && mp.count(j))
                z = solve(nums, arr[x], mp[j]);

            if(z) return true;
        }

        return dp[k][i] = false;
    }


    unordered_map<int, int> mp;
    vector<vector<int>> dp;

    bool canCross(vector<int>& nums) {
        int m = *max_element(nums.begin(), nums.end());
        dp.resize(nums.size(), vector<int>(nums.size(), -1) );
        for(int i = 0; i < nums.size(); i++) mp[nums[i]] = i;
        return solve(nums, 0, 0);
    }
};