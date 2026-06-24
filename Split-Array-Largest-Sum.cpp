1class Solution {
2public:
3    bool canAns(vector<int>& nums, int mid, int k) {
4        int s = 1;
5        int t = 0;
6
7        for(int x : nums) {
8            if(x > mid) return false;
9
10            if(t + x > mid) {
11                t = 0;
12                s++;
13            }
14
15            t += x;
16        }
17
18        return s <= k;
19    }
20
21    int splitArray(vector<int>& nums, int k) {
22        int n = nums.size();
23        
24        int i = *max_element(nums.begin(), nums.end()),
25        j = accumulate(nums.begin(), nums.end(), 0);
26
27        int ans = INT_MAX;
28
29
30        while(i <= j) {
31            int mid = i + (j-i)/2;
32
33
34            if(canAns(nums, mid, k)) {
35                ans = mid;
36                j = mid-1;
37            } else {
38                i = mid+1;
39            }
40        }
41
42        return ans;
43    }
44};