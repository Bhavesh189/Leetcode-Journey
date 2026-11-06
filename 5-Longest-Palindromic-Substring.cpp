class Solution {
public:

    string solve(string& s, int i, int j) {
        while(i>=0 && j < s.size() && s[i] == s[j]) {
            i--;
            j++;
        }

        return s.substr(i+1, j-i-1);
    }

    string longestPalindrome(string& s) {
        string ans = "";

        for(int i = 0; i < s.size(); i++) {
            string a = solve(s, i, i);
            string b = solve(s, i, i+1);

            if(a.size() > ans.size()) ans = a;
            if(b.size() > ans.size()) ans = b;
        }

        return ans;
    }
};