1class Solution {
2public:
3    string removeOuterParentheses(string s) {
4        string ans = "";
5        string temp = "";
6        int x = 0;
7
8        for(int i = 0; i < s.size(); i++) {
9            if(s[i] == '(') {
10                if(temp.empty()) {
11                    temp += '(';
12                } else {
13                    x++;
14                    ans += s[i];
15                }
16            } else {
17                if(x == 0) {
18                    temp = "";
19                } else {
20                    x--;
21                    ans += s[i];
22                }
23            }
24        }
25
26        return ans;
27    }
28};