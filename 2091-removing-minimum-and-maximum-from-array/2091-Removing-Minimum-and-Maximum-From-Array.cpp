class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int ans = INT_MAX;

        int mi = 0, mx = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[mi] > nums[i])
                mi = i;
            if (nums[mx] < nums[i])
                mx = i;
        }

        int n = nums.size();

        if (mi == mx) {
            return min(n - mi, mi + 1);
        }

        int both = (min(mi, mx) + 1) + (n - max(mi, mx));
        int front = max(mi, mx) + 1;
        int back = n - min(mi, mx);

        return min({both, front, back});
    }
};