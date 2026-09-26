class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int i = (n-1)/2, j = n-1;

        vector<int> ans(n);

        for(int k = 0; k < n; k++) {
            if(k%2 == 0) ans[k] = nums[i--];
            else ans[k] = nums[j--];
        }

        nums = ans;
    }
};