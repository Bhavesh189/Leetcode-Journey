1class Solution {
2public:
3    int beautySum(string s) {
4        int ans = 0;
5        
6
7        for(int j = 0; j < s.size(); j++) {
8            vector<int> freq(26, 0);
9            for(int i = j; i < s.size(); i++) {
10                char ch = s[i];
11
12                freq[ch-'a']++;
13
14                int mo = 0, mi = INT_MAX;
15
16                for(int x : freq) {
17                    if(x > 0) {
18                        mo = max(mo , x);
19                        mi = min(mi, x);
20                    }
21                }
22
23                ans += (mo-mi);
24
25            }
26        }
27
28        return ans;
29    }
30};