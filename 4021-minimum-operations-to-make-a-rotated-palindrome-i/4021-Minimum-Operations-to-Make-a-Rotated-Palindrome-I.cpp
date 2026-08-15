class Solution {
public:
    int minOperations(string s) {
        int ans = INT_MAX;
        int n = s.size();

        for(int k = 0; k < s.size(); k++) {
            int i = 0, j = s.size()-1;
            int cost = k;
            while (i < j) {
                int x = s[(k + i++) % n] - 'a';
                int y = s[(k + j--) % n] - 'a';
    
                cost += min((x - y + 26) % 26, (y - x + 26) % 26);    
            }

            ans = min(cost, ans);
        }

        return ans;
    }
};