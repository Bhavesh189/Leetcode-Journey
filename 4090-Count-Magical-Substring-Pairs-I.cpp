class Solution {
public:
    int countMagicalPairs(string s) {
        int ans = 0;

        for(int j = 0; j < s.size(); j++) {
            int d1 = 0, d2 = 0;
            vector<int> mp1(26, 0), mp2(26, 0);
            int arr[27] = {0};

            for(int k = j+1; k < s.size(); k++) {
                if(!mp1[s[k]-'a']++) d1++;

                arr[d1]++;
            }

            for(int i = j; i >= 0; i--) {
                if(!mp2[s[i]-'a']++) d2++;

                ans += arr[d2];
            }
        }

        return ans;
    }
};