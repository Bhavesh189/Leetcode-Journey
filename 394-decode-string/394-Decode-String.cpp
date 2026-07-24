class Solution {
public:

    string solve(string s, int& i) {
        string ans = "";
        int k = 0;

        while(i < s.size()) {
            char ch = s[i++];
            if(isdigit(ch)) {
                k = k*10 + (ch-'0');
            } else if(ch == '[') {
                string temp = solve(s, i);

                while(k > 0) {
                    ans += temp;
                    k--;
                }
                k=0;
            } else if(ch == ']') {
                return ans;
            } else {
                ans += ch;
            }
        }

        return ans;
    }

    string decodeString(string s) {
        int i = 0;
        return solve(s, i);
    }
};