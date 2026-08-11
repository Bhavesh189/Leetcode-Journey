class Solution {
public:
    bool dfs(int i, int j, vector<vector<char>>& nums,
             vector<vector<bool>>& vis, int m, int n, bool isValid) {
        if (i < 0 || j < 0 || j >= n || i >= m)
            return false;
        if (vis[i][j])
            return true;

        vis[i][j] = true;
        bool b = isValid;

        if (nums[i][j] == 'X')
            return true;
        if ((i == m - 1) || (j == n - 1) || (i == 0) || (j == 0))
            b = false;

        bool l = dfs(i - 1, j, nums, vis, m, n, b);
        bool r = dfs(i + 1, j, nums, vis, m, n, b);
        bool u = dfs(i, j - 1, nums, vis, m, n, b);
        bool d = dfs(i, j + 1, nums, vis, m, n, b);

        b = b && l && r && u && d;
        return b;
    }

    void k(int i, int j, vector<vector<char>>& nums, vector<vector<bool>>& vis,
           int m, int n) {
        if (i < 0 || j < 0 || j >= n || i >= m)
            return;
        if (vis[i][j])
            return;

        if (nums[i][j] == 'X')
            return;

        vis[i][j] = true;

        nums[i][j] = 'X';

        k(i - 1, j, nums, vis, m, n);
        k(i + 1, j, nums, vis, m, n);
        k(i, j - 1, nums, vis, m, n);
        k(i, j + 1, nums, vis, m, n);
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O' && !vis[i][j]) {
                    vector<vector<bool>> viss = vis;
                    bool x = dfs(i, j, board, viss, m, n, true);
                    if (x)
                        k(i, j, board, vis, m, n);
                }
            }
        }
    }
};