class Solution {
public:
    string smallestSubsequence(string s) {
        stack<char> st;
        string ans = "";
        vector<int> mp(26, 0);
        vector<int> u(26, 0);

        for (char ch : s)
            mp[ch - 'a']++;

        for (char ch : s) {
            mp[ch - 'a']--;
            if (u[ch - 'a'])
                continue;
            while (!st.empty() && st.top() >= ch && mp[st.top() - 'a']) {
                u[st.top() - 'a'] = 0;
                st.pop();
            }
            st.push(ch);

            u[ch - 'a'] = 1;
        }

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};