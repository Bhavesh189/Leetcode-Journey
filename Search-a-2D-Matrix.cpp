1class Solution {
2public:
3    bool searchMatrix(vector<vector<int>>& matrix, int target) {
4        int m = matrix.size(), n = matrix[0].size();
5        int i = 0, j = m*n-1;
6
7        while(i <= j) {
8            int mid = i + (j-i)/2;
9
10            int r = mid/n;
11            int c = mid%n;
12
13            if(matrix[r][c] == target) return true;
14            else if(matrix[r][c] < target) i = mid+1;
15            else j = mid-1;
16        }
17
18        return false;
19    }
20};