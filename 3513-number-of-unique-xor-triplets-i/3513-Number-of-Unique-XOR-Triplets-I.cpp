class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2) return n;
        int z = 0;

        for(int x : nums) z |= x;

        return z+1;
    }
};