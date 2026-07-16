class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int mx = nums[0];
        int n = nums.size();
        vector<int> pref(n, 0);

        for(int i = 0; i < n; i++) {
            mx = max(nums[i], mx);

            pref[i] = gcd(nums[i], mx);
        }

        sort(pref.begin(), pref.end());

        long long ans = 0;
        int i = 0, j = n-1;
        while(i < j) {
            ans += gcd(pref[i++], pref[j--]);
        }

        return ans;
    }
};