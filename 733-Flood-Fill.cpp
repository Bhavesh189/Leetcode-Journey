class Solution {
public:
    void dfs(vector<vector<int>>& nums, int i, int j, int c, int sc, vector<vector<bool>>& vis) {
        if (i >= m || i < 0 || j >= n || j < 0)
            return;

        if(nums[i][j] != sc) return;

        if(vis[i][j]) return;

        vis[i][j] = true;

        dfs(nums, i + 1, j, c, sc, vis);
        dfs(nums, i, j + 1, c, sc, vis);
        dfs(nums, i - 1, j, c, sc, vis);
        dfs(nums, i, j - 1, c, sc, vis);

        nums[i][j] = c;
    }

    int m, n;

    vector<vector<int>> floodFill(vector<vector<int>>& nums, int sr, int sc,
                                  int c) {
        m = nums.size(), n = nums[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        dfs(nums, sr, sc, c, nums[sr][sc], vis);

        return nums;
    }
};