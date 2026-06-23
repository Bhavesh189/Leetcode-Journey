1class Solution {
2public:
3    vector<int> searchRange(vector<int>& nums, int target) {
4        if(nums.empty()) return {-1, -1};
5        int start = -1, end = -1;
6
7        int i = 0, j = nums.size()-1;
8
9        while(i <= j) {
10            int mid = i + (j-i)/2;
11
12            if(nums[mid] < target) i = mid+1;
13            else if(nums[mid] > target) j = mid-1;
14            else if(mid-1 >= 0 && nums[mid-1] == target) j = mid-1;
15            else {
16                start = mid;
17                break;
18            }
19        }
20
21        i = 0, j = nums.size()-1;
22
23        while(i <= j) {
24            int mid = i + (j-i)/2;
25
26            if(nums[mid] < target) i = mid+1;
27            else if(nums[mid] > target) j = mid-1;
28            else if(mid+1 < nums.size() && nums[mid+1] == target) i = mid+1;
29            else {
30                end = mid;
31                break;
32            }
33        }
34        return {start, end};
35    }
36};