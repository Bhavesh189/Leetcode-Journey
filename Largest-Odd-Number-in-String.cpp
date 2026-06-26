1class Solution {
2public:
3    string solve(string& num, int j) {
4        if(0 == j) {
5            if(num[j]-'0'&1) return num.substr(0, j+1);
6            else return "";
7        }
8
9        if(num[j]-'0'&1) return num.substr(0, j+1);
10        else return solve(num, j-1);
11    }
12    string largestOddNumber(string& num) {
13        return solve(num, num.size()-1);
14    }
15};