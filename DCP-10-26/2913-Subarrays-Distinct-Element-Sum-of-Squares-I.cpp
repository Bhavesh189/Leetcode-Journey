class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            unordered_map<int, int> mp;
            int c = 0;
            for (int j = i; j < nums.size(); j++) {
                if(!mp[nums[j]]) {
                    mp[nums[j]]++;
                    c++;
                }
                ans += c*c;
            }
        }

        return ans;
    }
};