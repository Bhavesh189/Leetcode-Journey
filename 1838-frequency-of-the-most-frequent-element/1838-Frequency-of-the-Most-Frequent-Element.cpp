class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int l = 0;
        int ans = 0;
        long long sum = 0;

        for(int r = 0; r < nums.size(); r++) {

            while(l<r && (1LL)*(r-l)*nums[r]-sum > k) {
                sum -= nums[l++];
            }

            ans = max(ans, r-l+1);
            sum += nums[r];
        }

        return ans;
    }
};