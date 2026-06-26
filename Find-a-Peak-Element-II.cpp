1class Solution {
2public:
3    vector<int> findPeakGrid(vector<vector<int>>& mat) {
4        int m = mat.size(), n = mat[0].size();
5
6        int i = 0, j = n-1;
7
8        while(i <= j) {
9            int mid = i + (j-i)/2;
10
11            int mr = 0;
12
13            for(int ix = 0; ix < m; ix++) {
14                if(mat[ix][mid] > mat[mr][mid]) mr = ix;
15            }
16
17            int l = mid-1 >= 0 ? mat[mr][mid-1] : -1;
18            int r = mid+1 < n ? mat[mr][mid+1] : -1;
19
20            if(mat[mr][mid] > l && mat[mr][mid] > r) return {mr, mid};
21            else if(mat[mr][mid] < l) j = mid-1;
22            else i = mid+1;
23        }
24
25        return {-1, -1};
26    }
27};