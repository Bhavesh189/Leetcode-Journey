1class Solution {
2public:
3    bool isEat(int x, vector<int>& p, int h) {
4        int n = p.size();
5        long long t = 0;
6
7        for(int i = 0; i < n; i++) {
8                t += (p[i]+x-1)/x;
9                if(t > h) return false;
10        }
11
12        return true;
13    }
14    int minEatingSpeed(vector<int>& piles, int h) {
15        int mx = 0;
16
17        for(int x : piles) mx = max(x, mx);
18
19        int i = 1, j = mx;
20        int ans = INT_MAX;
21
22        while(i <= j) {
23            int mid = i + (j-i)/2;
24
25            if(isEat(mid, piles, h)) {
26                ans = min(ans, mid);
27                j = mid-1;
28            }
29            else i = mid+1;
30        }
31
32        return ans;
33    }
34};