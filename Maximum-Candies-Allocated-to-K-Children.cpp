1class Solution {
2public:
3    int maximumCandies(vector<int>& candies, long long k) {
4        int i = 1, j = *max_element(candies.begin(), candies.end());
5        int ans = 0;
6
7        while(i <= j) {
8            int mid = i + (j-i)/2;
9
10            long long x = 0;
11
12            for(int z : candies) {
13                x += z/mid;
14            }
15
16            if(x >= k) {
17                ans = max(ans, mid);
18                i = mid+1;
19            } else j = mid-1;
20        }
21
22        return ans;
23    }
24};