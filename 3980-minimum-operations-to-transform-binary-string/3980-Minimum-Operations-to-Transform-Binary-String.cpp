class Solution {
public:
    int minOperations(string s1, string s2) {
        if(s1 == s2) return 0;

        int ans = 0;

        for(int i = 0; i < s1.size(); i++) {
            if(s1[i] == s2[i]) continue;

            if(s1[i] == '0') {
                s1[i] = '1';
                ans++;
                continue;
            }

            if(i+1 < s1.size() && s1[i+1] == '1') {
                ans++;
                s1[i] = s1[i+1] = '0';
                continue;
            }

            if(i-1 >= 0 && s1[i-1] == '1') {
                ans++;
                ans += ('1' == s2[i-1]);
                s1[i-1] = s2[i-1];
                s1[i] = s2[i];
                continue;
            }

            if(i+1 < s1.size() && s1[i+1] == '0') {
                ans += 2;
                s1[i] = s2[i];
                continue;
            }

            if(i-1 >= 0 && s1[i-1] == '0') {
                ans += 2;
                s1[i-1] = s2[i-1];
                s1[i] = s2[i];
                continue;
            }
        }

        if(s1 != s2) return -1;

        return ans;
    }
};