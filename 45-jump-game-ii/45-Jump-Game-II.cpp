class Solution {
public:
    int jump(vector<int>& nums) {
        int ans = 0;
        int mj = 0;
        int l = 0;

        for(int i = 0; i < nums.size()-1; i++) {
            int l = max(l, i+nums[i]);

            if(i==mj) {
                ans++;
                mj = l;
            }
        }

        return ans;
    }
};