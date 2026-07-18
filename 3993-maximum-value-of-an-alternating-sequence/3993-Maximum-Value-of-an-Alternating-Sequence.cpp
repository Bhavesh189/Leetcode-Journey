class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        long long ans = s;

        long long p1 = n/2;

        if(p1 > 0) {
            long long x = 1LL*s + p1*1LL * m- (p1 - 1);
            ans = max(ans, x);
        }

        long long p2 = (n-1LL)/2;

        if(p2 > 0) {
            long long x = 1LL*s + p2*1LL * m- (p2);
            ans = max(ans, x);
        }

        return ans;
    }
};