class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        queue<pair<int, int>> q;

        int ans = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 2) q.push({i, j});
            }
        }

        while(!q.empty()) {
            int s = q.size();

            while(s--) {
                auto front = q.front();
                int i = front.first, j = front.second;
                grid[i][j] = 2;

                q.pop();

                if(i+1 < m && grid[i+1][j] == 1) {
                    q.push({i+1, j});
                    grid[i+1][j] = 2;
                }

                if(i-1 >= 0 && grid[i-1][j] == 1) {
                    q.push({i-1, j});
                    grid[i-1][j] = 2;
                }

                if(j+1 < n && grid[i][j+1] == 1) {
                    q.push({i, j+1});
                    grid[i][j+1] = 2;
                }

                if(j-1 >= 0 && grid[i][j-1] == 1) {
                    q.push({i, j-1});
                    grid[i][j-1] = 2;
                }

            }

            ans++;
        }

        bool a = true;

        for(auto x : grid) {
            for(auto y : x) {
                if(y == 1) return -1;
                if(y == 2) a = false;
            }
        }

        if(a) return 0;

        return ans-1;
    }
};