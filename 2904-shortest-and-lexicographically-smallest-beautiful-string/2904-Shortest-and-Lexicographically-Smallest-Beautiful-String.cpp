class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();

        string ans = "";
        int to = 0;

        int l = 0;

        for (int r = 0; r < s.size(); r++) {
            to += (s[r] == '1');

            while (l <= r && to > k) {
                to -= (s[l++] == '1');
            }

            while (l <= r && s[l] == '0')
                l++;

            if (to == k) {
                string st = s.substr(l, r - l + 1);

                if (ans == "" || st.size() < ans.size() || (st.size() == ans.size() && st < ans)) {
                    ans = st;
                }
            }
        }

        return ans;
    }
};