class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int one = 0, ans = 0;
        bool st = true;
        int prev = INT_MIN;

        for(int i = 0; i < s.size(); i++) {
            char ch = s[i];

            if(st && ch == '1') {
                one++;
                continue;
            } else st = false;
            
            int n = 0;

            while(i < s.size() && s[i] == '0') {
                n++;
                i++;
            }
            while(i < s.size() && s[i] == '1') {
                one++;
                i++;
            }

            ans = max(ans, prev+n);

            prev = n;
            i--;
        }

        return one + ans;
    }
};