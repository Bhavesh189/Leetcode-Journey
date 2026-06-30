1class Solution {
2public:
3
4    void solve(vector<vector<int>>& ans, vector<int> khali, vector<int>& nums, int t, int sum, int j) {
5        if(sum > t) return;
6        if(sum == t) {
7            ans.push_back(khali);
8            return;
9        }
10
11        for(int i = j; i < nums.size(); i++) {
12            if (sum + nums[i] > t) break;
13
14            khali.push_back(nums[i]);
15            solve(ans, khali, nums, t, sum+nums[i], i);
16            khali.pop_back();
17        }
18    }
19
20    vector<vector<int>> combinationSum(vector<int>& nums, int t) {
21        sort(nums.begin(), nums.end());
22
23        vector<vector<int>> ans;
24        vector<int> khali;
25
26        solve(ans, khali, nums, t, 0, 0);
27
28        return ans;
29    }
30};