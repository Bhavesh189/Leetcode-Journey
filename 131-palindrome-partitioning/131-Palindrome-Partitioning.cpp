class Solution {
public:
    bool isPal(string s) {
        int i = 0, j = s.size() - 1;

        while (i < j) {
            if (s[i] == s[j])
                i++, j--;
            else
                return false;
        }

        return true;
    }

    void solve(string& s, int idx, vector<string>& temp,
               vector<vector<string>>& ans) {
        if (idx == s.size()) {
            ans.push_back(temp);
            return;
        }

        for (int i = idx; i < s.size(); i++) {
            string send = s.substr(idx, i - idx + 1);
            if (isPal(send)) {
                temp.push_back(send);
                solve(s, i + 1, temp, ans);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;

        solve(s, 0, temp, ans);

        return ans;
    }
};