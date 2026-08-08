class Solution {
public:

    void dfs(int i, int j, vector<vector<char>>& nums, int m, int n) {
        if(i < 0 || j >= n || j < 0 || i >= m) return;
        if(nums[i][j] == '0') return;

        nums[i][j] = '0';

        dfs(i+1, j, nums, m, n);
        dfs(i-1, j, nums, m, n);
        dfs(i, j+1, nums, m, n);
        dfs(i, j-1, nums, m, n);
    }

    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int m = grid.size(), n = grid[0].size();

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == '1') {
                    dfs(i, j, grid, m, n);
                    ans++;
                }
            }
        }

        return ans;
    }
};