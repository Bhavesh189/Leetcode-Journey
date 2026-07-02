1class Solution {
2public:
3    int singleNumber(vector<int>& nums) {
4        int ans = 0;
5
6        for(int x : nums) {
7            ans ^= x;
8        }
9
10        return ans;
11    }
12};