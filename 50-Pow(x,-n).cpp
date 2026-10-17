class Solution {
public:
    double solve(double x, int n) {
        if(n == 0) return 1;
        if(n == 1) return x;

        double ans = solve(x, n/2);

        if(n&1) return ans*ans*x;
        else return ans*ans;
    }

    double myPow(double x, int n) {
        int nn = n;

        if(nn < 0) {
            return 1.0/solve(x, n);
        }

        return solve(x, n);
    }
};