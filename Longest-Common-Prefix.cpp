1class Solution {
2public:
3    string longestCommonPrefix(vector<string>& strs) {
4        string ans = "";
5
6        for(int i = 0; i < strs[0].size(); i++) {
7            char temp = strs[0][i];
8            
9            for(int j = 1; j < strs.size(); j++) {
10                if(strs[j][i] != temp) return ans;
11            }
12            ans += temp;
13        }
14
15        return ans;
16    }
17};