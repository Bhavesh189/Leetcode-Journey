1class Solution {
2public:
3    void solve(vector<vector<string>>& ans, vector<vector<int>>& mp, int n,
4               int j, vector<string>& dal) {
5
6        if (j >= n) {
7            ans.push_back(dal);
8            return;
9        }
10
11        for (int i = 0; i < n; i++) {
12            if (!mp[i][j]) {
13                dal[i][j] = 'Q';
14                for (int x = 0; x < n; x++) {
15                    mp[i][x]++;
16                    mp[x][j]++;
17                }
18                for (int d = 1; d < n; d++) {
19                    if (i + d < n && j + d < n)
20                        mp[i + d][j + d]++;
21                    if (i - d >= 0 && j - d >= 0)
22                        mp[i - d][j - d]++;
23                    if (i + d < n && j - d >= 0)
24                        mp[i + d][j - d]++;
25                    if (i - d >= 0 && j + d < n)
26                        mp[i - d][j + d]++;
27                }
28
29                solve(ans, mp, n, j + 1, dal);
30
31                for (int x = 0; x < n; x++) {
32                    mp[i][x]--;
33                    mp[x][j]--;
34                }
35                for (int d = 1; d < n; d++) {
36                    if (i + d < n && j + d < n)
37                        mp[i + d][j + d]--;
38                    if (i - d >= 0 && j - d >= 0)
39                        mp[i - d][j - d]--;
40                    if (i + d < n && j - d >= 0)
41                        mp[i + d][j - d]--;
42                    if (i - d >= 0 && j + d < n)
43                        mp[i - d][j + d]--;
44                }
45                dal[i][j] = '.';
46            }
47        }
48    }
49
50    vector<vector<string>> solveNQueens(int n) {
51        vector<vector<int>> mp(n, vector<int>(n));
52        vector<vector<string>> ans;
53        vector<string> dal;
54        string s = "";
55        for (int i = 0; i < n; i++) {
56            s += '.';
57        }
58        for (int i = 0; i < n; i++) {
59            dal.push_back(s);
60        }
61
62        solve(ans, mp, n, 0, dal);
63
64        return ans;
65    }
66};