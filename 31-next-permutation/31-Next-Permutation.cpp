class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int p = -1;
        int n = nums.size();

        for(int i = n-2; i >= 0; i--) {
            if(nums[i] < nums[i+1]) {
                p = i;
                break;
            }
        }

        if(p == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        int mi = INT_MAX, idx = -1;

        for(int i = n-1; i >= 0; i--) {
            if(nums[i] > nums[p]) {
                swap(nums[i], nums[p]);
                break;
            }
        }

        reverse(nums.begin()+p+1, nums.end());
    }
};