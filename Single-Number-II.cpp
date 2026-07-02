1class Solution {
2public:
3    int singleNumber(vector<int>& nums) {
4        int ans = 0;
5
6        for(int i = 0; i < 32; i++) {
7            int count = 0;
8            for(int x : nums) {
9                if(1&(x>>i)) {
10                    count++;
11                }
12            }
13            if(count%3) ans |= 1<<i;
14        }
15
16        return ans;
17    }
18};