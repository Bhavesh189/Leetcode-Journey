class Solution {
public:

    bool isValid(string& s) {
        if(s.empty()) return false;
        if(s[0] == '0' && s.size() > 1) return false;
        if(stoi(s) > 255) return false;
        if(s.size() > 3) return false;

        return true;
    }

    void solve(string& s, string khali, vector<string>& ans, int i, int dots) {
        if((dots == 4) && (s.size() == i)) {
            khali.pop_back();
            ans.push_back(khali);
            return;
        }

        if(dots > 4 || s.size() <= i) return;

        for(int j = 1; (j <= 3) && (j+i <= s.size()); j++) {
            string temp = s.substr(i, j);

            if(isValid(temp)) {
                solve(s, khali + temp + ".", ans, i+j, dots+1);
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        string khali = "";
        vector<string> ans;

        solve(s, khali, ans, 0, 0);

        return ans;
    }
};