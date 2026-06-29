1class Solution {
2public:
3    double solve(double x, long long n) {
4        if(n == 1) return x;
5        if(n == 0) return 1;
6
7        double a = solve(x, n/2);
8
9        if(n&1) return a*a*x;
10        else return a*a;
11    }
12    double myPow(double x, int n) {
13        long long nn = n;
14        if(n < 0) {
15            x = 1/x;
16            nn = -nn;
17        }
18        if(n == 0) return 1;
19        if(n == 1) return x;
20        return solve(x, nn);
21    }
22};