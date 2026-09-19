class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] >= 0 && k > 0) break;
            else {
                k--;
                nums[i] = -nums[i];
                if(k == 0) break;
            }
        }

        sort(nums.begin(), nums.end());

        k = k%2;

        if(k) nums[0] = -nums[0];

        return accumulate(nums.begin(), nums.end(), 0);
    }
};