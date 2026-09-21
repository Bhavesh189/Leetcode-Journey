class Solution {
public:
    int maxDistance(vector<vector<int>>& nums) {
        int n = nums.size();

        int mx = nums[0][nums[0].size()-1], mn = nums[0][0];
        int ans = 0;

        for(int i = 1; i < nums.size(); i++) {
            ans = max(ans, abs(mx-nums[i][0]));
            ans = max(ans, abs(mn-nums[i].back()));

            mx = max(mx, nums[i].back());
            mn = min(mn, nums[i][0]);
        }

        return ans;
    }
};