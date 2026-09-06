class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return 0;

        int s = 0, e = n - 1;

        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (mid + 1 < n && nums[mid] < nums[mid + 1]) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }

        return s;
    }
};