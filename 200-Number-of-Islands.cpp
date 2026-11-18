class Solution {
public:
    void solve(vector<vector<char>>& nums, int i, int j, int m, int n) {
        if (i < 0 || j < 0 || i >= m || j >= n || nums[i][j] == '0')
            return;
        nums[i][j] = '0';

        solve(nums, i + 1, j, m, n);
        solve(nums, i, j + 1, m, n);
        solve(nums, i - 1, j, m, n);
        solve(nums, i, j - 1, m, n);
    }

    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;

        int m = grid.size(), n = grid[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    solve(grid, i, j, m, n);
                    ans++;
                }
            }
        }

        return ans;
    }
};