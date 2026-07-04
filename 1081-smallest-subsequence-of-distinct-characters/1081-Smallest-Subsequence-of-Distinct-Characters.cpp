class Solution {
public:
    string smallestSubsequence(string &s) {
        unordered_map<int, int> mp;
        unordered_map<int, int> aa;

        for(char &ch : s) mp[ch]++;

        stack<int> st;

        for(char &ch : s) {
            mp[ch]--;
            if(aa[ch]) continue;

            while(!st.empty() && st.top() > ch && mp[st.top()]) {
                aa[st.top()] = false;
                st.pop();
            }

            st.push(ch);
            aa[ch] = true;
        }

        string ans = "";

        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;

    }
};