class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        for(int i = 0; i < numRows; i++) {
            vector<int> row(i+1);

            row[0] = row[row.size()-1] = 1;

            for(int j = 1; j < row.size()-1; j++) {
                int lr = i-1;

                int ele = ans[lr][j-1] + ans[lr][j];

                row[j] = ele;
            }

            ans.push_back(row);
        }

        return ans;
    }
};