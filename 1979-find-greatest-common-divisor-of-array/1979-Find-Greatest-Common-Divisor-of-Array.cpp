class Solution {
public:
    int findGCD(vector<int>& nums) {
        int m = *max_element(nums.begin(), nums.end());
        int mi = *min_element(nums.begin(), nums.end());

        return gcd(mi, m);
    }
};