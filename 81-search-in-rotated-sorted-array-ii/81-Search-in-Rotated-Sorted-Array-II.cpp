class Solution {
public:
    bool search(vector<int>& nums, int t) {
        int n = nums.size();

        int s = 0, e = n - 1;

        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (nums[mid] == t)
                return true;
            else if (nums[s] == nums[mid] && nums[mid] == nums[e]) {
                s++;
                e--;
            } else if (nums[s] <= nums[mid]) {
                if (nums[s] <= t && nums[mid] >= t)
                    e = mid - 1;
                else
                    s = mid + 1;
            } else {
                if (nums[mid] <= t && nums[e] >= t)
                    s = mid + 1;
                else
                    e = mid - 1;
            }
        }

        return false;
    }
};