class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN, s = 0;

        for(int x : nums) {
            s += x;
            ans = max(ans, s);
            if(s < 0) s = 0;
        }

        return ans;
    }
};