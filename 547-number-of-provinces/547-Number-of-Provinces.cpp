class Solution {
public:

    void dfs(int node, vector<vector<int>>& nums, vector<bool>& vis) {
        if(vis[node]) return;
        vis[node] = true;

        for(int i = 0; i < nums[node].size(); i++) {
            if(nums[node][i]) {
                dfs(i, nums, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& nums) {
        vector<bool> mp(nums.size(), false);
        int ans = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(!mp[i]) {
                dfs(i, nums, mp);
                ans++;
            }
        }

        return ans;
    }
};