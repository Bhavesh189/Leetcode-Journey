1class Solution {
2public:
3    // bool canAns(int i, vector<int>& nums, int t) {
4    //     int d = 0;
5
6    //     for (int x : nums) {
7    //         d += (x + i - 1) / i;
8    //         if (d > t)
9    //             return false;
10    //     }
11
12    //     return d <= t;
13    // }
14
15    int smallestDivisor(vector<int>& nums, int t) {
16        int ans = INT_MAX;
17
18        sort(nums.begin(), nums.end());
19
20        int i = 1, j = *max_element(nums.begin(), nums.end());
21
22        while (i <= j) {
23            int mid = i + (j - i) / 2;
24
25            int d = 0;
26
27            for (int x : nums) {
28                d += (x + mid - 1) / mid;
29                if (d > t) break;
30            }
31
32            if (d <= t) {
33                ans = min(ans, mid);
34                j = mid - 1;
35            } else
36                i = mid + 1;
37        }
38
39        return ans;
40    }
41};