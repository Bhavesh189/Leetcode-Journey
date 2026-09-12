class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int ans = 0;
        int m = g.size(), n = s.size();
        
        int i = 0, j = 0;

        while(i < m && j < n) {
            if(s[j] >= g[i]) {
                ans++;
                i++;
                j++;
            }
            else j++;
        }

        return ans;
    }
};