class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(), ans, pos, neg;
        ans = pos = neg = nums[0];

        for(int i = 1; i < n; i++) {
            int temp = pos;
            pos = max({nums[i], nums[i]*pos, nums[i]*neg});
            neg = min({nums[i], nums[i]*temp, nums[i]*neg});

            ans = max(ans, pos);
        }

        return ans;
    }
};