class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> ans;

        int c = 0;
        int t = 0, l = 0, r = n - 1, b = m - 1;

        while (c < m * n) {

            if (c < m * n)
                for (int i = l; i <= r; i++) {
                    ans.push_back(matrix[t][i]);
                    c++;
                }
            t++;

            if (c < m * n)
                for (int i = t; i <= b; i++) {
                    ans.push_back(matrix[i][r]);
                    c++;
                }
            r--;

            if (c < m * n)
                for (int i = r; i >= l; i--) {
                    ans.push_back(matrix[b][i]);
                    c++;
                }
            b--;

            if (c < m * n)
                for (int i = b; i >= t; i--) {
                    ans.push_back(matrix[i][l]);
                    c++;
                }
            l++;
        }

        return ans;
    }
};