class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;

        int mid = nums.size()/2;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] < nums[mid]) {
                ans += nums[mid] - nums[i];
            } else {
                ans += nums[i] - nums[mid];
            }
        }

        return ans;
    }
};