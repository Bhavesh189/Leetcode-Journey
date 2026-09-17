class Solution {
public:

    // vector<vector<int>> merge(vector<vector<int>>& nums) {
    //     vector<vector<int>> ans;
    //     ans.push_back(nums[0]);

    //     for(int i = 1; i < nums.size(); i++) {
    //         if(nums[i][0] < ans.back()[1]) {
    //             ans.back()[1] = min(ans.back()[1], nums[i][1]);
    //         } else {
    //             ans.push_back(nums[i]);
    //         }
    //     }

    //     return ans;
    // }

    int eraseOverlapIntervals(vector<vector<int>>& nums) {
        sort(nums.begin(), nums.end());

        // nums = merge(intervals);
        int ans = 0;
        int mn2 = nums[0][1];

        for(int i = 1; i < nums.size(); i++) {
            if(mn2 > nums[i][0]) {
                mn2 = min(mn2, nums[i][1]);
                ans++;
            }
            else mn2 = max(mn2, nums[i][1]);
        }

        return ans;
    }
};