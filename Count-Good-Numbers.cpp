1class Solution {
2public:
3    long long MOD = 1e9 + 7;
4
5    long long pow(long long x, long long n) {
6        x = x%MOD;
7        long long ans = 1;
8
9        while(n > 0) {
10            if(n&1) ans = (ans*x)%MOD;
11            x = (x*x) % MOD;
12            n/=2;
13        }
14
15        return ans%MOD;
16    }
17
18    int countGoodNumbers(long long n) {
19        return (pow(5, (n+1)/2) * pow(4, (n)/2)) % MOD;
20    }
21};