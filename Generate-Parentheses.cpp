1class Solution {
2public:
3
4    void solve(vector<string>& ans, string khali, int n, int open, int close) {
5
6        if(khali.size() == n*2) {
7            ans.push_back(khali);
8        }
9
10        if(open < n)
11
12        solve(ans, khali+'(', n, open+1, close);
13
14        if(close < open)
15
16        solve(ans, khali+')', n, open, close+1);
17    }
18
19    vector<string> generateParenthesis(int n) {
20        vector<string> ans;
21        string khali;
22
23        solve(ans, khali, n, 0, 0);
24
25        return ans;
26    }
27};