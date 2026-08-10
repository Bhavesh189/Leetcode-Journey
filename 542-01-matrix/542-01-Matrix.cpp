class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();

        vector<vector<int>> vis(m, vector<int>(n, -1));

        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!mat[i][j]) {
                    q.push({i, j});
                    vis[i][j] = 0;
                }
            }
        }

        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            if (i + 1 < m && vis[i + 1][j] == -1) {
                vis[i + 1][j] = vis[i][j] + 1;
                q.push({i + 1, j});
            }
            if (j + 1 < n && vis[i][j + 1] == -1) {
                vis[i][j + 1] = vis[i][j] + 1;
                q.push({i, j + 1});
            }
            if (i - 1 >= 0 && vis[i - 1][j] == -1) {
                vis[i - 1][j] = vis[i][j] + 1;
                q.push({i - 1, j});
            }
            if (j - 1 >= 0 && vis[i][j - 1] == -1) {
                vis[i][j - 1] = vis[i][j] + 1;
                q.push({i, j - 1});
            }
        }

        return vis;
    }
};