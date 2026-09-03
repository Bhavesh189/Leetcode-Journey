class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int n = nums.size();
        bool odd = true;

        int mo = INT_MAX;

        for (int x : nums)
            if (x & 1)
                mo = min(x, mo);

        if (mo == INT_MAX)
            return true;

        for (int i = 0; i < n; i++) {
            if (nums[i] & 1)
                continue;
            if (nums[i] <= mo) {
                odd = false;
                break;
            }
        }

        return odd;
    }
};