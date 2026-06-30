1class Solution {
2public:
3
4    void solve(vector<vector<int>>& ans, vector<int> khali, vector<int>& nums,
5               int t, int sum, int j) {
6        if (sum > t)
7            return;
8        if (sum == t) {
9            ans.push_back(khali);
10            return;
11        }
12
13        for (int i = j; i < nums.size(); i++) {
14            if (i > j && nums[i] == nums[i - 1]) continue;
15            
16            if (sum + nums[i] > t)
17                break;
18
19            khali.push_back(nums[i]);
20            solve(ans, khali, nums, t, sum + nums[i], i + 1);
21            khali.pop_back();
22        }
23    }
24    vector<vector<int>> combinationSum2(vector<int>& nums, int t) {
25        sort(nums.begin(), nums.end());
26
27        vector<vector<int>> ans;
28        vector<int> khali;
29
30        solve(ans, khali, nums, t, 0, 0);
31
32        return ans;
33    }
34};