1class Solution {
2public:
3    bool rotateString(string s, string goal) {
4        if(s.size() != goal.size()) return false;
5        goal += goal;
6
7        for(int i = 0; i < s.size(); i++) {
8            if(goal.substr(i, s.size()) == s) return true;
9        }
10
11        return false;
12    }
13};