class Solution {
public:

    long long gc(long long a, long long b) {
        return b == 0 ? a : gc(b, a % b);
    }

    long long lc(long long a, long long b) {
        return (a / gc(a, b)) * b;
    }

    int maxLength(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            long long prod = 1, lcm = 1, gcd = 0;
            for(int j = i; j < n; j++) {
                if (prod > LLONG_MAX / nums[j]) break;
                prod *= nums[j];
                lcm = lc(lcm, nums[j]), gcd = gc(gcd, nums[j]);

                if(prod == gcd*lcm) ans = max(ans, j-i+1);
            }
        }

        return ans;
    }
};