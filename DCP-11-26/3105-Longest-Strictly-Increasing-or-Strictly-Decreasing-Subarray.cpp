class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans = 1;
        int n = nums.size();

        int l = 0;

        for(int r = 1; r < n; r++) {
            while(l<r && nums[r-1] >= nums[r]) l++;
            ans = max(ans, r-l+1);
        }

        l = 0;

        for(int r = 1; r < n; r++) {
            while(l<r && nums[r-1] <= nums[r]) l++;
            ans = max(ans, r-l+1);
        }

        return ans;
    }
};