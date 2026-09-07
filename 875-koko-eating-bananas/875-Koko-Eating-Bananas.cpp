class Solution {
public:
    bool canAns(vector<int>& nums, int h, int mid) {
        long long y = 0;

        for (int x : nums) {
            y += (x+mid-1)/mid;
            if(y>h) return false;
        }

        return true;
    }

    int minEatingSpeed(vector<int>& nums, int h) {
        int ans = INT_MAX;

        int s = 1,
            e = *max_element(nums.begin(), nums.end());

        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (canAns(nums, h, mid)) {
                ans = min(ans, mid);
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }

        return ans;
    }
};