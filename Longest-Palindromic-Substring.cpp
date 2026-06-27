1class Solution {
2public:
3    string bhar(string s, int i, int j) {
4        while(i >= 0 && j < s.size() && (s[i] == s[j])) {
5            i--;
6            j++;
7        }
8
9        return s.substr(i+1, j-i-1);
10    }
11    
12    string longestPalindrome(string s) {
13        int n = s.size();
14
15        string ans = "";
16
17        for(int i = 0; i < n; i++) {
18            string one = bhar(s, i, i);
19            string two = bhar(s, i, i+1);
20
21            if(one.size() > ans.size()) ans = one;
22            if(two.size() > ans.size()) ans = two;
23        }
24
25        return ans;
26    }
27};