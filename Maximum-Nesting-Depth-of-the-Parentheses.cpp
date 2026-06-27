1class Solution {
2public:
3    int maxDepth(string s) {
4        int ans = 0;
5        int open = 0;
6
7        for(char ch : s) {
8            if(ch == '(') open++;
9            else if(ch == ')') open--;
10
11            ans = max(ans, open);
12        }
13
14        return ans;
15    }
16};