class Solution {
public:

    long long rev(long long n) {
        long long ans = 0;

        while(n != 0) {
            int d = n%10;
            ans = ans*10 + d;
            n /= 10;
        }

        return ans;
    }

    long long sumAndMultiply(int n) {
        long long x = 0, sum = 0;

        while(n != 0) {
            int d = n%10;
            sum += d;
            if(d != 0) x *= 10;
            x+=d;
            n /= 10;
        }

        x = rev(x);

        return x*sum;
    }
};