1class Solution {
2public:
3
4    void solve(vector<vector<int>>& ans, vector<int> khali, int i, vector<int>& nums) {
5        if(i >= nums.size()) {
6            ans.push_back(khali);
7            return;
8        }
9
10        khali.push_back(nums[i]);
11
12        solve(ans, khali, i+1, nums);
13
14        khali.pop_back();
15
16        solve(ans, khali, i+1, nums);
17    }
18
19    vector<vector<int>> subsets(vector<int>& nums) {
20        vector<vector<int>> ans;
21        vector<int> khali;
22
23        solve(ans, khali, 0, nums);
24
25        return ans;
26    }
27};