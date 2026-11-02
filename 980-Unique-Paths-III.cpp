class Solution {
public:

    bool canAns(vector<vector<int>>& nums) {
        for(auto x : nums) {
            for(int y : x) {
                if(y == 0) return false;
            }
        }

        return true;
    }

    int solve(vector<vector<int>>& nums, int i, int j, int m, int n) {
        if (i >= m || j >= n || i < 0 || j < 0)
            return 0;
        // if(dp[i][j] != -1) return dp[i][j];

        if (nums[i][j] == 2) {
            if (canAns(nums))
                return 1;
            else
                return 0;
        }

        if(nums[i][j] == -1) return 0;

        int x = nums[i][j];

        nums[i][j] = -1;

        int ans = solve(nums, i + 1, j, m, n) + solve(nums, i - 1, j, m, n) +
               solve(nums, i, j + 1, m, n) + solve(nums, i, j - 1, m, n);

        nums[i][j] = x;

        return ans;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1)
                    return solve(grid, i, j, grid.size(), grid[0].size());
            }
        }

        return 0;
    }
};