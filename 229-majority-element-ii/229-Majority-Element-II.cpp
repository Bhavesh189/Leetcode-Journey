class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int c1 = INT_MIN, c2 = INT_MIN;
        int v1 = 0, v2 = 0;
        int n = nums.size();
        int h = ceil(n / 3);

        for (const int& x : nums) {
            if (c1 == x) {
                v1++;
            } else if (c2 == x) {
                v2++;
            } else if (v1 == 0) {
                c1 = x;
                v1 = 1;
            } else if (v2 == 0) {
                c2 = x;
                v2 = 1;
            } else {
                v1--, v2--;
            }
        }
        v1 = v2 = 0;

        for (const int& x : nums) {
            if (x == c1)
                v1++;
            if (x == c2)
                v2++;
        }

        if (v1 > h && v2 > h)
            return {c1, c2};
        else if (v1 > h)
            return {c1};
        else if (v2 > h)
            return {c2};
        else
            return {};
    }
};