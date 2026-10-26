class Solution {
public:

    bool dfs(vector<vector<char>>& grid, int i, int j,
                  vector<vector<bool>>& vis, int m, int n) {
        long long res = 0;
        if (i >= m || j >= n || i < 0 || j < 0 || grid[i][j] == '0' || vis[i][j])
            return 0;

        vis[i][j] = true;

        res += grid[i][j] + dfs(grid, i - 1, j, vis, m, n) +
               dfs(grid, i, j - 1, vis, m, n) + dfs(grid, i, j + 1, vis, m, n) +
               dfs(grid, i + 1, j, vis, m, n);

        return 1;
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        int ans = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == '1' && !vis[i][j]) ans += dfs(grid, i, j, vis, m, n);
            }
        }

        return ans;
    }
};