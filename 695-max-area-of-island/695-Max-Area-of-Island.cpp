class Solution {
public:

    int dfs(int i, int j, vector<vector<int>>& nums, int m, int n) {
        if(i >= m || j >= n || i < 0 || j < 0) return 0;
        if(nums[i][j] == 0) return 0;

        nums[i][j] = 0;

        int l = dfs(i+1, j, nums, m, n);
        int r = dfs(i-1, j, nums, m, n);
        int t = dfs(i, j+1, nums, m, n);
        int b = dfs(i, j-1, nums, m, n);

        return 1 + l + r + t + b;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        int ans = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j]) ans = max(ans, dfs(i, j, grid, m, n));
            }
        }

        return ans;
    }
};