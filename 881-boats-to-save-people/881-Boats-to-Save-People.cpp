class Solution {
public:
    int numRescueBoats(vector<int>& nums, int limit) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = 0, j = n-1;
        int ans = 0;

        while(i <= j) {
            if((nums[i] + nums[j]) <= limit) i++;
            j--;

            ans++;
        }

        return ans;
    }
};