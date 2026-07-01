1class Solution {
2public:
3
4    bool isValid(vector<vector<char>>& board, int i, int j, char x) {
5        
6        for(int q = 0; q < 9; q++) {
7            if(board[q][j] == x) return false;
8            if(board[i][q] == x) return false;
9            if(board[3 * (i / 3) + q / 3][3 * (j / 3) + q % 3] == x) return false;
10        }
11
12        return true;
13    }
14
15    bool solve(vector<vector<char>>& board) {
16        for(int i = 0; i < 9; i++) {
17            for(int j = 0; j < 9; j++) {
18                if(board[i][j] == '.') {
19                    for(int x = '1'; x <= '9'; x++) {
20                        if(isValid(board, i, j, x)) {
21                            board[i][j] = x;
22                            if(solve(board)) return true;
23                            board[i][j] = '.';
24                        }
25                    }
26                    return false;
27                }
28            }
29        }
30
31        return true;
32    }
33
34    void solveSudoku(vector<vector<char>>& board) {
35        solve(board);
36    }
37};