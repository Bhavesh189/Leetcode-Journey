class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int z = 0;
        int XOR = 0;
        int n = nums.size();

        for(int x : nums) {
            if(x == 0) z++;
            XOR ^= x;
        }

        if(z == n) return 0;

        if(!XOR) return n-1;
        return n;
    }
};