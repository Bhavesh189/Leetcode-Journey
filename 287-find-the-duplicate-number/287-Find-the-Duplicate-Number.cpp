class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            int x = nums[i]-1;

            if(i != x) {
                if(nums[i] == nums[x]) return nums[x];
                swap(nums[i], nums[x]);
                i--;
            }
        }

        return n;
    }
};