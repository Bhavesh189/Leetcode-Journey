class Solution {
public:
    bool stoneGameIX(vector<int>& nums) {
        vector<int> mp(3, 0);
        bool ans = false;

        for(int x : nums) mp[x%3]++;

        if(mp[0]%2 == 0) return mp[1] && mp[2];
        else return (abs(mp[1] - mp[2]) > 2);
    }
};