class Solution {
public:

    void solve(vector<int>& nums, vector<int>& khali, vector<vector<int>>& ans, int i) {
        if(nums.size() == i) {
            ans.push_back(khali);
            return;
        }

        solve(nums, khali, ans, i+1);

        khali.push_back(nums[i]);
        solve(nums, khali, ans, i+1);
        khali.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> khali;

        solve(nums, khali, ans, 0);

        return ans;
    }
};