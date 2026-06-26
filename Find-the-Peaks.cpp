1class Solution {
2public:
3    vector<int> findPeaks(vector<int>& nums) {
4        int n = nums.size();
5        vector<int> ans;
6
7        for(int i = 1; i < n-1; i++) {
8            if((nums[i] > nums[i - 1]) && (nums[i] > nums[i + 1])) ans.push_back(i);
9        }
10
11        return ans;
12    }
13};