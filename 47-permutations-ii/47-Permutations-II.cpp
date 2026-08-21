class Solution {
public:
    void solve(vector<vector<int>>& ans, vector<int>& nums, int i) {
        if (i >= nums.size()) {
            ans.push_back(nums);
            return;
        }

        unordered_map<int, int> mp;

        for (int j = i; j < nums.size(); j++) {
            if (mp[nums[j]])
                continue;
            mp[nums[j]] = true;
            swap(nums[i], nums[j]);
            solve(ans, nums, i + 1);
            swap(nums[i], nums[j]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        solve(ans, nums, 0);

        return ans;
    }
};