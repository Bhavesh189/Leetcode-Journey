class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int mul = 1;
        bool isZero = 0, all = 1, d = 0;
        int dd = 0;

        for(int x : nums) {
            if(x == 0) {
                isZero = true;
                dd++;
                continue;
            }
            mul *= x;
            all = 0;
        }

        if(dd >= 2) mul = 0;

        if(all) {
            for(int &x : nums) x = 0;
            return nums;
        }

        for(int i = 0; i < n; i++) {
            if(isZero) {
                if(nums[i] == 0) nums[i] = mul;
                else nums[i] = 0;
            } else nums[i] = mul/nums[i];
        }

        return nums;
    }
};