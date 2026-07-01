1class Solution {
2public:
3
4    bool isPal(string s) {
5        int i = 0, j = s.size()-1;
6
7        while(i < j) {
8            if(s[i++] != s[j--]) return false;
9        }
10
11        return true;
12    }
13
14    void solve(vector<vector<string>>& ans, vector<string> khali, string s, int i) {
15        if(i >= s.size()) {
16            ans.push_back(khali);
17            return;
18        }
19
20        for(int j = i; j < s.size(); j++) {
21            string p = s.substr(i, j-i+1);;
22            if(isPal(p)) {
23                khali.push_back(p);
24                solve(ans, khali, s, j+1);
25                khali.pop_back();
26            }
27        }
28    }
29
30    vector<vector<string>> partition(string s) {
31        vector<vector<string>> ans;
32        vector<string> khali;
33
34        solve(ans, khali, s, 0);
35
36        return ans;
37    }
38};