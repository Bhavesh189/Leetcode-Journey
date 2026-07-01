1class Solution {
2public:
3
4    bool solve(string word, vector<vector<char>>& board, int i, int j, int x, vector<vector<bool>>& mp) {
5        int m = board.size(), n = board[0].size();
6
7        if(x == word.size()) return true;
8        if(i >= m || j >= n || i < 0 || j < 0) return false;
9
10        if(word[x] == board[i][j]) {
11            if(x == word.size()-1) return true;
12            mp[i][j] = true;
13            bool ans = false;
14
15            if(i-1 >= 0 && !mp[i-1][j]) {
16                ans = ans || solve(word, board, i-1, j, x+1, mp);
17            }
18
19            if(i+1 < m && !mp[i+1][j]) {
20                ans = ans || solve(word, board, i+1, j, x+1, mp);
21            }
22
23            if(j-1 >= 0 && !mp[i][j-1]) {
24                ans = ans || solve(word, board, i, j-1, x+1, mp);
25            }
26
27            if(j+1 < n && !mp[i][j+1]) {
28                ans = ans || solve(word, board, i, j+1, x+1, mp);
29            }
30
31            mp[i][j] = false;
32
33            return ans;
34        }
35        
36        else return false;
37
38    }
39
40    bool exist(vector<vector<char>>& board, string word) {
41        int m = board.size(), n = board[0].size();
42
43        vector<vector<bool>> mp(m, vector<bool>(n));
44
45        for(int i = 0; i < board.size(); i++) {
46            for(int j = 0; j < board[0].size(); j++) {
47                if(board[i][j] == word[0]) {
48                    mp[i][j] = true;
49                    if(solve(word, board, i, j, 0, mp)) return true;
50                    mp[i][j] = false;
51                }
52            }
53        }
54
55        return false;
56    }
57};