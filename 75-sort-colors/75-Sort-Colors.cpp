class Solution {
public:
    void sortColors(vector<int>& nums) {
        int o = 0, j = nums.size()-1;

        for(int i = 0; i <= j; i++) {
            if(nums[i] == 0) {
                swap(nums[i], nums[o++]);
            }
            if(nums[i] == 2) {
                swap(nums[i--], nums[j--]);
            }
        }
    }
};