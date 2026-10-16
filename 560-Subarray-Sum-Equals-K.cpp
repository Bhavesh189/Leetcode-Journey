class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int sum = 0, ans = 0;
        mp[0] = 1;

        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            int f = sum-k;

            if(mp.count(f)) ans += mp[f];

            mp[sum]++;
        }

        return ans;
    }
};