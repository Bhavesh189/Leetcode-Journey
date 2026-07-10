class Solution {
public:
    int minAllOneMultiple(int k) {
        int ans = 0;
        long long n = 0;

        while(ans < k) {
            n = (n*10+1)%k;
            ans++;
            if(n == 0) return ans;
        }

        return -1;
    }
};