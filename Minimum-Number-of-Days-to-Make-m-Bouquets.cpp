1class Solution {
2public:
3    bool isDone(int i, vector<int>& nums, int m, int k) {
4        int s = 0;
5        int temp = 0;
6
7        for(int q = 0; q < nums.size(); q++) {
8            if(nums[q] <= i) {
9                s++;
10                if(s == k) {
11                    temp++;
12                    s = 0;
13                }
14            } else s = 0;
15        }
16
17        return temp >= m ? true : false;
18    }
19
20    int minDays(vector<int>& nums, int m, int k) {
21        int n = nums.size();
22        if(n < (long long)m*k) return -1;
23
24        long long minDays = *min_element(nums.begin(), nums.end()),
25        maxDays = *max_element(nums.begin(), nums.end());
26
27        long long i = minDays, j = maxDays;
28        long long ans = INT_MAX;
29
30        while(i <= j) {
31            long long mid = i + (j-i)/2;
32
33            if(isDone(mid, nums, m, k)) {
34                ans = min(mid, ans);
35                j = mid-1;
36            } else i = mid+1;
37        }
38
39        return ans;
40    }
41};