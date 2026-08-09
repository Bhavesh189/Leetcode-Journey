class Solution {
public:

    void dfs(vector<vector<int>>& nums, int i, int j, int c, int m, int n, int x) {
        if(i >= m || j >= n || i < 0 || j < 0) return;

        if(nums[i][j] == c) return;
        if(nums[i][j] != x) return;

        nums[i][j] = c;

        dfs(nums, i, j+1, c, m, n, x);
        dfs(nums, i, j-1, c, m, n, x);
        dfs(nums, i+1, j, c, m, n, x);
        dfs(nums, i-1, j, c, m, n, x);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size(), n = image[0].size();

        dfs(image, sr, sc, color, m, n, image[sr][sc]);

        return image;
    }
};