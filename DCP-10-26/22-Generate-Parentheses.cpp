class Solution {
public:

    void solve(int n, string s, int open, int close, vector<string>& ans) {
        if(open == close && open == n) {
            ans.push_back(s);
            return;
        }
        

        if(open+1 <= n) {
            solve(n, s+'(', open+1, close, ans);
        }

        if(close+1 <= open) {
            solve(n, s+')', open, close+1, ans);
        }
    }

    vector<string> generateParenthesis(int n) {
        int open = 0, close = 0;

        vector<string> ans;
        solve(n, "", open, close, ans);

        return ans;
    }
};