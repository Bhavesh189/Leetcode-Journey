1class Solution {
2public:
3    bool search(vector<int>& nums, int target) {
4        int n = nums.size();
5
6        int i = 0, j = n-1;
7
8        while(i <= j) {
9            int mid = i + (j-i)/2;
10            
11            if(nums[mid] == target) {
12                return true;
13            }
14
15            if(nums[i] == nums[mid] && nums[mid] == nums[j]) {
16                i++;
17                j--;
18            }
19            else if(nums[i] <= nums[mid]) {
20                if(target <= nums[mid] && target >= nums[i]) j = mid-1;
21                else i = mid+1;
22            } else {
23                if(target <= nums[j] && target >= nums[mid]) i = mid+1;
24                else j = mid-1;
25            }
26        }
27
28        return false;
29    }
30};