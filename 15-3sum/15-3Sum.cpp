class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int c = nums[i];

            int j = i + 1, k = nums.size() - 1;

            while (j < k) {
                int a = nums[j];
                int b = nums[k];
                int sum = a + b + c;
                if (!sum) {
                    ans.push_back({a, b, c});
                    while (j < k && nums[j] == nums[j + 1])
                        j++;
                    while (j < k && nums[k] == nums[k - 1])
                        k--;
                    k--;
                    j++;
                } else if (sum > 0) {
                    k--;
                } else {
                    j++;
                }
            }
        }

        return ans;
    }
};