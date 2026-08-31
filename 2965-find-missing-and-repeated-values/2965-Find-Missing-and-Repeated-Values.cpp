class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_map<int, int> mp;
        int sum = 0, b = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid.size(); j++) {
                sum += grid[i][j];
                mp[grid[i][j]]++;
                if (mp[grid[i][j]] > 1)
                    b = grid[i][j];
            }
        }

        int n = grid.size();

        n *= n;

        int a = n * (n + 1) / 2;
        a -= sum;

        return {b, a+b};
    }
};