class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans;

        int c = 0;
        int x = n;
        string s = "";
        while(n--) s += '#';
        n = x;

        while(c < m) {
            ans.push_back(s);
            c++;
        }

        for(int i = 0; i < m; i++) {
            ans[i][0] = '.';
        }

        for(int i = 0; i < n; i++) {
            ans[m-1][i] = '.';
        }

        return ans;
    }
};