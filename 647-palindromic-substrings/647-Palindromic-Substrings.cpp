class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            int p, q;
            p = q = i;

            while (p >= 0 && q < n && s[p] == s[q]) {
                p--, q++, ans++;
            }

            p = q = i;
            q++;

            while (p >= 0 && q < n && s[p] == s[q]) {
                p--, q++, ans++;
            }
        }

        return ans;
    }
};