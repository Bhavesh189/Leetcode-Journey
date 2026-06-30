1class Solution {
2public:
3
4    void solve(int i, int n, int k, vector<int> khali, vector<vector<int>>& ans, int sum) {
5        if(sum == n && khali.size() == k) {
6            ans.push_back(khali);
7            return;
8        }
9        
10        if(i > 9 || sum > n || khali.size() > k) return;
11
12        for(int j = i; j < 10; j++) {
13            khali.push_back(j);
14            solve(j+1, n, k, khali, ans, sum + j);
15            khali.pop_back();
16        }
17    }
18
19    vector<vector<int>> combinationSum3(int k, int n) {
20        vector<vector<int>> ans;
21        vector<int> khali;
22
23        solve(1, n, k, khali, ans, 0);
24
25        return ans;
26    }
27};