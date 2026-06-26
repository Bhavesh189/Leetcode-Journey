1class Solution {
2public:
3    string reverseWords(string s) {
4        vector<string> w;
5        string temp = "";
6
7        for(char ch : s) {
8            if(ch == ' ') {
9                if(!temp.empty()) {
10                    w.push_back(temp);
11                    temp = "";
12                }
13            } else {
14                temp += ch;
15            }
16        }
17
18        if(!temp.empty()) w.push_back(temp);
19        reverse(w.begin(), w.end());
20
21        temp = "";
22
23        for(int i = 0; i < w.size(); i++) {
24            temp += w[i];
25            if(i != w.size()-1) temp += ' ';
26        }
27
28        return temp;
29    }
30};