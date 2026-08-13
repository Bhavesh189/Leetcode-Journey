class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int temp = 0;
        int x = 0;
        int ans = 0;

        for(int i = 0; i < n; i++) {
            nums[i] -= temp;
            if(!nums[i]) continue;
            temp += nums[i];
            ans++;
        }

        return ans;
    }
};