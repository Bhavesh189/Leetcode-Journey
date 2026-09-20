class Solution {
public:
    int reverseDegree(string s) {
        int arr[26];
        int x = 26;
        int ans = 0;

        for(int i = 0; i < 26; i++) {
            arr[i] = x--;
        }

        for(int i = 0; i < s.size(); i++) {
            ans += arr[s[i]-'a']*(i+1);
        }

        return ans;
    }
};