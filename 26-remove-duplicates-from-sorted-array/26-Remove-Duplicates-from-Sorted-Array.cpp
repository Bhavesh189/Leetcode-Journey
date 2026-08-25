class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();

        if(n <= 1) return n;
        int i = 1;

        for(int j = 1; j < nums.size(); j++) {
            if(nums[j] != nums[i-1]) swap(nums[i++], nums[j]);
        }

        return i;
    }
};