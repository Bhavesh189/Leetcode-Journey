1class Solution {
2public:
3
4    void solve(string num, vector<string>& ans, string khali, int t, long long res, long long prev, int i) {
5        if(i == num.size()) {
6            if(res == t) ans.push_back(khali);
7            return;
8        }
9
10        for(int j = i; j < num.size(); j++) {
11            if(j > i && num[i] == '0') break;
12            string st = num.substr(i, j-i+1);
13
14            long long val = stoll(st);
15
16            if(i == 0) {
17                solve(num, ans, st, t, res+val, val, j+1);
18            }
19            else {
20                solve(num, ans, khali + '+' + st, t, res+val, val, j+1);
21                solve(num, ans, khali + '-' + st, t, res-val, -val, j+1);
22                solve(num, ans, khali + '*' + st, t, (res - prev) + val*prev, prev*val, j+1);
23            }
24        }
25
26    }
27
28    vector<string> addOperators(string num, int target) {
29        vector<string> ans;
30        string khali = "";
31
32        solve(num, ans, khali, target, 0, 0, 0);
33
34        return ans;
35    }
36};