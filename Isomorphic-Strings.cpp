1class Solution {
2public:
3    bool isIsomorphic(string s, string t) {
4        if(s.size() != t.size()) return false;
5
6        unordered_map<char, char> mp1;
7        unordered_map<char, char> mp2;
8
9        for(int i = 0; i < s.size(); i++) {
10            char a = s[i], b = t[i];
11
12            if(mp1.count(a) && mp1[a] != b) return false;
13            if(mp2.count(b) && mp2[b] != a) return false;
14
15            mp1[a] = b;
16            mp2[b] = a;
17        }
18
19        return true;
20
21    }
22};