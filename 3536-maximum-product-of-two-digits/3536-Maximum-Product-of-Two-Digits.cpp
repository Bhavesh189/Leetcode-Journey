class Solution {
public:
    int maxProduct(int n) {
        int l,m;

        l = m = 0;

        while(n > 0) {
            int d = n%10;

            if(d > m) {
                l=m;
                m = d;
            } else if(d > l) {
                l = d;
            }

            n /= 10;
        }

        return l*m;
    }
};