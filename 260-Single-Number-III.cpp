class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        if(nums.size() == 2) return nums;

        int XOR = 0;

        for(int x : nums) {
            XOR ^= x;
        }

        int XOR1 = 0, XOR2 = 0;
        uint32_t y = uint32_t(XOR) & -uint32_t(XOR);

        for(int x : nums) {


            if(x & y) {
                XOR1 ^= x;
                continue;
            } 
            
            if(!(x & y)) {
                XOR2 ^= x;
                continue;
            }
            XOR1 ^= x;
            XOR2 ^= x;
        }

        return {XOR1, XOR2};
    }
};