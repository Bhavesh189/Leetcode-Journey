class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];

        int p1, p2;
        p1 = p2 = 0;
        int ans = 0;

        for(int& x : nums) {
            ans = max(x+p2, p1);
            p2 = p1;
            p1 = ans;
        }

        return ans;
    }
};