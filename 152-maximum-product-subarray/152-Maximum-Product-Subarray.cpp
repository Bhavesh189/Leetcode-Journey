class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans, PM, NM;

        ans = PM = NM = nums[0];

        for(int i = 1; i < nums.size(); i++) {
            int x = nums[i];

            if(x < 0) swap(PM, NM);

            PM = max(x, PM*x);
            NM = min(NM*x, x);

            ans = max(ans, PM);
        }

        return ans;
    }
};