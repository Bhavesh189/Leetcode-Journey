1class Solution {
2public:
3    int hammingWeight(int n) {
4        int ans = 0;
5        
6        while(n != 0) {
7            n = n & (n-1);
8            ans++;
9        }
10
11        return ans;
12    }
13};