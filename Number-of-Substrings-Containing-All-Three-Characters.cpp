1class Solution {
2public:
3    int numberOfSubstrings(string s) {
4        int ans = 0;
5
6        int a = 0, b = 0, c = 0;
7
8        int l = 0;
9
10        for(int r = 0; r < s.size(); r++) {
11            if(s[r] == 'a') a++;
12            if(s[r] == 'b') b++;
13            if(s[r] == 'c') c++;
14            if(r-l+1 < 3) continue;
15
16            while(a > 0 && b > 0 && c > 0 && l < s.size()) {
17                int t = s.size()-1;
18                ans += t - r + 1;
19
20                if(s[l] == 'a') a--;
21                if(s[l] == 'b') b--;
22                if(s[l] == 'c') c--;
23
24                l++;
25            }
26        }
27
28        return ans;
29    }
30};