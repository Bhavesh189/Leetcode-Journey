class Solution {
public:
    string truncateSentence(string s, int k) {
        int i = 0;
        int n = s.size();

        string ans = "";

        for(char ch : s) {
            if(ch == ' ') k--;
            if(!k) return ans;
            ans += ch;
        }

        return ans;
    }
};