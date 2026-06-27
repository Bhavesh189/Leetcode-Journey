1class Solution {
2public:
3    string frequencySort(string s) {
4        unordered_map<char, int> mp;
5
6        for(char ch : s) {
7            mp[ch]++;
8        }
9
10        vector<pair<int, char>> v;
11
12        for(auto it : mp) {
13            v.push_back({it.second, it.first});
14        }
15
16        s = "";
17
18        sort(v.rbegin(), v.rend());
19
20        for(auto it : v) {
21            while(it.first--)
22            s += it.second;
23        }
24
25        return s;
26    }
27};