class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> suff(n, 0);
        int mn = nums[n-1], mx = nums[0];

        for(int i = n-1; i >= 0; i--) {
            mn = min(mn, nums[i]);

            suff[i] = mn;
        }

        for(int i = 0; i < n; i++) {
            mx = max(mx, nums[i]);

            if(1LL*(mx - suff[i]) <= k) return i;
        }

        return -1;
    }
};