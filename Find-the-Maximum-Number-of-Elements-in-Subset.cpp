1class Solution {
2public:
3    int maximumLength(vector<int>& nums) {
4        unordered_map<long long, int> mp;
5        long long ans = 0;
6
7        for(int x : nums) mp[x]++;
8
9        if(mp.find(1) != mp.end()) {
10            long long f = mp[1];
11
12            if(f % 2 == 0) f--;
13
14            ans = max(ans, f);
15        }
16
17        for(auto it : mp) {
18            long long curr = it.first, len = 0;
19            if(curr == 1) continue;
20
21            while(mp.count(curr) && mp[curr] > 1) {
22                len += 2;
23                curr = curr*curr;
24            }
25
26            if(mp.find(curr) != mp.end()) {
27                len += 1;
28            } else {
29                len -= 1;
30            }
31
32            ans = max(ans, len);
33        }
34
35        return ans;
36    }
37};