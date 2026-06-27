1class Solution {
2public:
3    int myAtoi(string s) {
4        int i = 0, sign = 1;
5        int n = s.size();
6        long long ans = 0;
7
8        while (i < n && s[i] == ' ')
9            i++;
10
11        if (i < n && s[i] == '+' || s[i] == '-') {
12            sign = (s[i] == '+') ? 1 : -1;
13            i++;
14        }
15
16        while (i < n && isdigit(s[i])) {
17            int d = s[i] - '0';
18
19            if (ans > (INT_MAX - d) / 10)
20                return (sign == 1) ? INT_MAX : INT_MIN;
21
22            ans = ans * 10 + d;
23
24            i++;
25        }
26
27        return ans * sign;
28    }
29};