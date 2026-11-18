class Solution {
public:
    int minChanges(string s) {
        int prev = -1;

        int ans = 0;

        for(char& ch : s) {
            if(prev == -1) {
                prev = ch-'0';
            } else {
                if(ch != prev+'0') ans++;
                prev = -1;
            }
        }

        return ans;
    }
};