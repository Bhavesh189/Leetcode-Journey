class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return true;
        int j = n - 1;

        for (int i = n - 2; i >= 0; i--) {
            if (i + nums[i] >= j)
                j = i;
            if (i == 0 && (j == i))
                return true;
        }

        return false;
    }
};