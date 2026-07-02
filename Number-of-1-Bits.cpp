1class Solution {
2public:
3    int hammingWeight(int n) {
4        int ans = 0;
5        for(int i = 0; i < 32; i++) {
6            if(n&1) ans++;
7            n >>= 1;
8        }
9
10        return ans;
11    }
12};