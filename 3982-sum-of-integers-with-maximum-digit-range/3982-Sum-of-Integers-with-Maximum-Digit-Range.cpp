class Solution {
public:

    int get(int n) {
        int m = INT_MIN, mi = INT_MAX;

        while(n != 0) {
            int d = n%10;

            m = max(m, d);
            mi = min(mi, d);

            n /= 10;
        }

        return m-mi;
    }
    
    int maxDigitRange(vector<int>& nums) {
        int ans = 0;

        int r = -1;

        for(int x : nums) {
            int d = get(x);
            if(d == r) {
                ans += x;
            } else if(d > r) {
                ans = x;
            }

            r = max(d, r);
        }

        return ans;
    }
};