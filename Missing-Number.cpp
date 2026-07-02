1class Solution {
2public:
3    int missingNumber(vector<int>& nums) {
4        int n = nums.size();
5        int ans = 0;
6
7        for(int i = 0; i < n; i++) {
8            ans ^= i+1^nums[i];
9        }
10
11        return ans;
12    }
13};