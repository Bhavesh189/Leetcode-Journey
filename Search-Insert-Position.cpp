1class Solution {
2public:
3    int searchInsert(vector<int>& nums, int target) {
4        int n = nums.size();
5        int i = 0, j = n-1;
6
7        while(i <= j) {
8            int mid = i + (j-i)/2;
9
10            if(nums[mid] < target) i = mid+1;
11            else if(nums[mid] > target) j = mid-1;
12            else return mid;
13        }
14
15        return i;
16    }
17};