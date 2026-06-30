1class Solution {
2public:
3
4    void solve(string arr[], vector<string>& ans, string khali, int i, string digits) {
5        if(i >= digits.size()) {
6            ans.push_back(khali);
7            return;
8        }
9
10        int d = digits[i]-'0';
11        string s = arr[d];
12
13        for(int j = 0; j < s.size(); j++) {
14            khali.push_back(s[j]);
15            solve(arr, ans, khali, i+1, digits);
16            khali.pop_back();
17        }
18    }
19
20    vector<string> letterCombinations(string digits) {
21        vector<string> ans;
22        string khali = "";
23        string arr[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
24
25        solve(arr, ans, khali, 0, digits);
26
27        return ans;
28    }
29};