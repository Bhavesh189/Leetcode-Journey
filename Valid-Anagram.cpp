1class Solution {
2public:
3    bool isAnagram(string s, string t) {
4        vector<int> mp1(26, 0);
5        vector<int> mp2(26, 0);
6
7        for(char ch : s) {
8            mp1[ch-'a']++;
9        }
10
11        for(char ch : t) {
12            mp2[ch-'a']++;
13        }
14
15        return mp1 == mp2;
16    }
17};