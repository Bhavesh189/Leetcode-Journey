class Solution {
public:
    long long countValidSubstrings(string s) {
        long long ans = 0;
        int n = s.size();

        int A = -1, AB = -1, last = -1;

        for (int i = 0; i < n; i++) {
            if (s[i] == 'a')
                A = i;
            else if (s[i] == 'b') {
                if (A != -1)
                    AB = A;
            } else {
                if (AB != -1)
                    last = max(last, AB);
            }

            ans += i - last;
        }

        return ans;
    }
};