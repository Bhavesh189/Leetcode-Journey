class Solution {
public:
    long long countValidSubstrings(string s) {
        long long ans = 0, l = 0;

        for(int r = 0; r < s.size(); r++) {

            if(r>= 2 && s[r] == 'c' && s[r-1] == 'b' && s[r-2] == 'a') l = r-1;

            ans += r-l+1;
        }

        return ans;
    }
};