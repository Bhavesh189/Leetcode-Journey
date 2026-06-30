1class Solution {
2public:
3
4    void solve(vector<vector<int>>& ans, vector<int> khali, int i, vector<int>& nums) {
5
6        ans.push_back(khali);
7
8        for(int j = i; j < nums.size(); j++) {
9            if(j>i && nums[j] == nums[j-1]) continue;
10
11            khali.push_back(nums[j]);
12            solve(ans, khali, j+1, nums);
13            khali.pop_back();
14        }
15    }
16
17    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
18        sort(nums.begin(), nums.end());
19        vector<vector<int>> ans;
20        vector<int> khali;
21
22        solve(ans, khali, 0, nums);
23
24        return ans;
25    }
26};