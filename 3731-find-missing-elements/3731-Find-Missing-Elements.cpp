class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int m = *max_element(nums.begin(), nums.end());
        int mi = *min_element(nums.begin(), nums.end());

        unordered_map<int, int> mp;
        for(int x : nums) mp[x]++;
        vector<int> ans;

        for(int i = mi; i <= m; i++) if(!mp[i]) ans.push_back(i);

        return ans;
    }
};