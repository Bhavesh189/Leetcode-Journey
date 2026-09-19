class Solution {
public:
    bool canPlaceFlowers(vector<int>& nums, int n) {
        int c = 0;

        for (int i = 0; i < nums.size(); i++) {
            int li = i - 1;
            int ni = i + 1;
            if (li == -1)
                li = 0;
            if (ni == nums.size())
                ni = nums.size() - 1;

            if (nums[li] == nums[ni] && nums[li] == 0 && nums[i] != 1) {
                nums[i] = 1;
                c++;
            }
        }

        return c >= n;
    }
};