class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for (int& x : nums)
            if(x<0) x=-x;

        long long ans = 0;

        int i = 0, j = nums.size() - 1;

        sort(nums.begin(), nums.end());
        bool add = true;

        while (i <= j) {
            if (add) {
                add = false;
                ans += (long long)(nums[j] * nums[j]);
                j--;
            } else {
                add = true;
                ans -= (long long)(nums[i] * nums[i]);
                i++;
            }
        }

        return ans;
    }
};