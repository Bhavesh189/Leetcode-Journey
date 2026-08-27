class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int ans = 0;
        int le = INT_MAX;

        for(int x : nums) {
            if(x<=le) le = x;
            else ans = max(ans, x-le);
        }

        return ans;
    }
};