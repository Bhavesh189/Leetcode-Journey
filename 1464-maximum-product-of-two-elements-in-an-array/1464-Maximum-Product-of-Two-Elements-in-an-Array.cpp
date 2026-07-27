class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int m, n;

        m = n = 0;

        for(int x : nums) {
            if(x > m) {
                n = m;
                m = x;
            } else if(x > n) {
                n = x;
            }
        }
        
        m--;n--;

        return m*n;
    }
};