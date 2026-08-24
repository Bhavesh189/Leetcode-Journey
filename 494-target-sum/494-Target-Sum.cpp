class Solution {
public:
    int ans = 0;

    void solve(vector<int>& nums, int num, int i, int sum, int& target) {
        if(nums.size() == i) {
            if(num == target) {
                ans++;
            }
            return;
        }

        solve(nums, num+nums[i], i+1, 0, target);
        solve(nums, num-nums[i], i+1, 0, target);
    }
    int findTargetSumWays(vector<int>& nums, int target) {

        solve(nums, nums[0], 1, 0, target);
        solve(nums, -nums[0], 1, 0, target);

        return ans;
    }
};