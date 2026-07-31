class Solution {
public:
    int minimumPushes(string word) {
        int ans = 0;
        vector<int> v(26, 0);

        for(char ch : word) v[ch-'a']++;

        sort(v.rbegin(), v.rend());
        int c = 0;

        for(int i = 0; i < 26; i++) {
            if(v[i]) c++;

            if(c > 8 && c <= 16) ans += 2*v[i];
            else if(c <= 8) ans += v[i];
            else if(c >= 17 && c <= 24) ans += 3*v[i];
            else ans += 4*v[i];
        }

        return ans;
    }
};