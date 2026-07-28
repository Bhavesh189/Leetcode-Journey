class Solution {
public:
    string smallestPalindrome(string s) {
        if (s.size() <= 1)
            return s;
        vector<int> v(26, 0);

        for (char ch : s)
            v[ch - 'a']++;
        string ans = "";

        int n = s.size();

        char ch = s[n / 2];
        if (n % 2)
            v[ch - 'a']--;

        for (int i = 0; i < 26; i++) {
            while (v[i]) {
                v[i] -= 2;

                ans += i + 'a';
            }
        }

        string temp = ans;
        reverse(ans.begin(), ans.end());
        if (n % 2)
            temp += ch;
        temp += ans;
        ans = temp;

        return ans;
    }
};