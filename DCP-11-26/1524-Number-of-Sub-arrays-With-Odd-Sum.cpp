class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long long MOD = 1e9+7;
        long long ans, ps;
        ans = ps = 0;
        int e = 1, o = 0;

        for (int x : arr) {
            ps += x;

            if (ps & 1) {
                ans += e;
                o++;
            } else {
                ans += o;
                e++;
            }

            ans %= MOD;
        }

        return ans;
    }
};