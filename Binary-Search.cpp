1class Solution {
2public:
3    int search(vector<int>& nums, int target) {
4        int i = 0, j = nums.size()-1;
5
6        while(i <= j) {
7            int mid = i + (j-i)/2;
8
9            if(nums[mid] < target) i++;
10            else if(nums[mid] > target) j--;
11            else return mid;
12        }
13
14        return -1;
15    }
16};