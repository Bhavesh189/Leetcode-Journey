class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        if (!k)
            return grid;
        int m = grid.size(), n = grid[0].size();
        int t = m * n;
        k = k % t;

        vector<int> temp;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                temp.push_back(grid[i][j]);
            }
        }

        reverse(temp.begin(), temp.end());
        reverse(temp.begin(), temp.begin()+k);
        reverse(temp.begin()+k, temp.end());

        for(int i =0; i < t; i++) {
            grid[i/n][i%n] = temp[i];
        }

        return grid;
    }
};