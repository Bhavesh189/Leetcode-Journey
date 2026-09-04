class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pref(n, 0), suff(n, 0);
        int mx = nums[0], mn = nums[n-1];

        for(int i = 0; i < n; i++) {
            mx = max(nums[i], mx);

            pref[i] = mx;
        }

        int ans = -1;

        for(int i = n-1; i >= 0; i--) {
            mn = min(nums[i], mn);

            suff[i] = mn;
            if((pref[i]-suff[i]) <= k) ans = i;
        }

        return ans;
    }
};