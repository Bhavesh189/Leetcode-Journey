class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0, m = 1000;

        while(n >= m) {
            ans += n-m+1;
            m*=1000;
        }

        return ans;
    }
};