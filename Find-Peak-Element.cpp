1class Solution {
2public:
3    int findPeakElement(vector<int>& nums) {
4        int n = nums.size();
5        int i = 0, j = n-1;
6
7        while(i < j) {
8            int mid = i + (j-i)/2;
9
10            if(nums[mid] < nums[mid+1]) i = mid+1;
11            else j = mid;
12        }
13        return i;
14    }
15};