class Solution {
public:
    bool checkDivisibility(int n) {
        long long sum = 0, mul = 1;
        int m = n;

        while(n != 0) {
            int digit = n%10;
            sum += digit;
            mul *= digit;

            n /= 10;
        }

        long long can = sum + mul;
        return !(m%can);
    }
};