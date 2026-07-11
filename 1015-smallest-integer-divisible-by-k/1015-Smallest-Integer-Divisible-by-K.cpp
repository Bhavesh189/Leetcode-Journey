class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int ans = 0;
        int n = 0;

        for (int i = 0; i < k; i++) {
            n = ((n * 10) + 1) % k;
            ans++;
            if (!n)
                return ans;
        }

        return -1;
    }
};