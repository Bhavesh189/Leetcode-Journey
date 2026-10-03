class Solution {
public:
    int longestValidParentheses(string s) {
        int open = 0, close = 0;
        int ans = 0;

        for(char ch : s) {
            if(ch == ')') close++;
            else open++;

            if(close > open) open = close = 0;

            if(open == close) ans = max(ans, close*2);
        }

        open = close = 0;

        for(int i = s.size()-1; i >= 0; i--) {
            if(s[i] == ')') close++;
            else open++;

            if(open > close) open = close = 0;

            if(open == close) ans = max(ans, open*2);
        }

        return ans;
    }
};