class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<int, int> mp;
        unordered_map<int, int> vis;

        for(int x : s) mp[x]++;

        stack<char> st;

        for(char ch : s) {
            mp[ch]--;
            if(vis[ch]) continue;

            while(!st.empty() && st.top() >= ch && mp[st.top()] > 0) {
                vis[st.top()] = false;
                st.pop();
            }

            st.push(ch);

            vis[ch] = true;
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