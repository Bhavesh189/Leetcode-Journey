1class Solution {
2public:
3    bool searchMatrix(vector<vector<int>>& matrix, int target) {
4        int m = matrix.size(), n = matrix[0].size();
5
6        int i = 0, j = n-1;
7
8        while(i < m && j >= 0) {
9            if(matrix[i][j] == target) return true;
10            else if(matrix[i][j] < target) i++;
11            else j--;
12        }
13
14        return false;
15    }
16};