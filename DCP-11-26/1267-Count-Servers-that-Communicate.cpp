class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        unordered_map<int, int> row, col;
        int totalServers = 0, notTalkingServers = 0;
        int m = grid.size(), n = grid[0].size();

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    row[i]++;
                    col[j]++;
                    totalServers++;
                }
            }
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j]) {
                    if(row[i] == 1 && col[j] == 1) notTalkingServers++;
                }
            }
        }

        return totalServers - notTalkingServers;
    }
};