class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        int o = 0;

        for (char ch : s) {
            if (ch == '(')
                o++;
            else if (ch == ')')
                o--;
            ans = max(ans, o);
        }

        return ans;
    }
};