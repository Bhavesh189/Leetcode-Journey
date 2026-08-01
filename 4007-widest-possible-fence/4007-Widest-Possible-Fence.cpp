class Solution {
public:
    int maximumWidth(vector<int>& nums) {
        unordered_map<int, int> c, a;

        for (int x : nums) {
            c[x]++;
            a[x]++;
        }

        for (auto x : c) {
            int p = x.first;
            for (auto y : c) {
                int q = y.first;

                if (p == q)
                    a[p + q] += c[p] / 2;
                if (p < q)
                    a[p + q] += min(c[p], c[q]);
            }
        }

        int ans = 0;

        for (auto x : a)
            ans = max(ans, x.second);

        return ans;
    }
};