class Solution {
public:

    void solve(vector<int>& nums, vector<vector<int>>& ans, vector<int>& temp, int t, int idx, int sum) {
        int n = nums.size();

        if(sum == t) {
            ans.push_back(temp);
            return;
        }
        if(sum > t || idx >= n) return;

        for(int i = idx; i < n; i++) {
            if(i > idx && nums[i] == nums[i-1]) continue;

            temp.push_back(nums[i]);

            solve(nums, ans, temp, t, i+1, sum+nums[i]);

            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;

        solve(nums, ans, temp, target, 0, 0);

        return ans;
    }
};