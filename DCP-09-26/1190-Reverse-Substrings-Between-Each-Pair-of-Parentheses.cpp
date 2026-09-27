class Solution {
public:
    string reverseParentheses(string s) {
        vector<int> c;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') c.push_back(i);
            else if(s[i] == ')') {
                int idx = c.back();
                c.pop_back();

                reverse(s.begin() + idx + 1, s.begin() + i);
            }
        }

        string ans = "";

        for(char ch : s) if(ch != '(' && ch != ')') ans += ch;

        return ans;
    }
};