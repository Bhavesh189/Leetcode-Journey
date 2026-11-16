class Solution {
public:

    int digitSum(string s) {
        int ans = 0;

        for(int i = s.size()-1; i >= 0; i--) {
            ans += (s[i]-'0');
        }

        return ans;
    }

    string digitSum(string s, int k) {
        if(s.size() <= k) return s;

        string st = "";

        while(s.size() > k) {
            vector<int> v;

            for(int i = 0; i < s.size(); i+=k) {
                v.push_back(digitSum(s.substr(i, k)));
            }

            s = "";

            for(int x : v) {
                s += to_string(x);
            }
        }

        return s;
    }
};