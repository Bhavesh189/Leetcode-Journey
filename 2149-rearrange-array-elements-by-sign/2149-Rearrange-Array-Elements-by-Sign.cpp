class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans(nums.size());

        int p = 0, n = 1;

        for(int x : nums) {
            if(x>0) {
                ans[p] = x;
                p += 2;
            } else {
                ans[n] = x;
                n += 2;
            }
        }

        return ans;
    }
};