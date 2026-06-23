1class Solution {
2public:
3    int search(vector<int>& nums, int target) {
4        int i = 0, j = nums.size()-1;
5
6        while(i <= j) {
7            int mid = i + (j-i)/2;
8
9            if(nums[mid] == target) return mid;
10
11            if(nums[i] <= nums[mid]) {
12                if(nums[i] <= target && nums[mid] >= target) j = mid-1;
13                else i = mid+1;
14            } else {
15                if(nums[mid] <= target && nums[j] >= target) i = mid+1;
16                else j = mid-1;
17            }
18        }
19
20        return -1;
21    }
22};