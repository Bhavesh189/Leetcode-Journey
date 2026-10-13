class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;

        for(int i = 0; i < n; i++) {
            int c = -nums[i];
            if(i>0 && nums[i] == nums[i-1]) continue;

            int j = i+1, k = n-1;

            while(j < k) {
                int a = nums[j], b = nums[k];

                if(a+b == c) {
                    ans.push_back({a, b, -c});
                    while(j<k && nums[j]==nums[j+1]) j++;
                    while(j<k && nums[k]==nums[k-1]) k--;
                    j++;
                    k--;
                } else if(a+b < c) {
                    j++;
                } else {
                    k--;
                }
            }
        }

        return ans;
    }
};