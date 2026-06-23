1class Solution {
2public:
3    int findMin(vector<int>& nums) {
4        int n = nums.size();
5
6        int i = 0, j = n-1;
7        int ans = INT_MAX;
8
9        while(i <= j) {
10            int mid = i + (j-i)/2;
11
12            if(nums[i] <= nums[mid]) {
13                ans = min({ans, nums[i]});
14                i = mid+1;
15            } else {
16                ans = min({ans, nums[mid]});
17                j = mid-1;
18            }
19        }
20
21        return ans;
22    }
23};