class Solution {
public:

    bool isPalindrome(string& s) {
        int i = 0, j = s.size()-1;

        while(i<j && s[i] == s[j]) {
            i++;
            j--;
        }

        if(i<j) return false;

        return true;
    }

    void solve(string& s, vector<string>& temp, int i, vector<vector<string>>& ans) {
        if(i >= s.size()) {
            if(temp.size() != 0) ans.push_back(temp);
            return;
        }


        for(int j = i; j < s.size(); j++) {
            string pal = s.substr(i, j-i+1);

            if(!pal.empty() && isPalindrome(pal)) {
                temp.push_back(pal);
                solve(s, temp, j+1, ans);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;

        solve(s, temp, 0, ans);

        return ans;
    }
};