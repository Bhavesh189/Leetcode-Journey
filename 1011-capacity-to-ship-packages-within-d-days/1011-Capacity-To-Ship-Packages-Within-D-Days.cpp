class Solution {
public:
    bool canAns(vector<int>& nums, int mid, int days) {
        int td = 1;
        int sum = 0;

        for (int x : nums) {
            if (sum + x > mid) {
                td++;
                sum = x;
            } else {
                sum += x;
            }

            if (td > days)
                return false;
        }

        return td <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size(), s = *max_element(weights.begin(), weights.end()),
            e = accumulate(weights.begin(), weights.end(), 0);
        int ans = INT_MAX;

        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (canAns(weights, mid, days)) {
                ans = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }

        return ans;
    }
};