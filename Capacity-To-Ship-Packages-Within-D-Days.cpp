1class Solution {
2public:
3    int shipWithinDays(vector<int>& weights, int days) {
4        int sum = 0;
5        int ans = INT_MAX;
6
7        for(int x : weights) sum += x;
8
9        int i = *max_element(weights.begin(), weights.end()), j = sum;
10
11        while(i <= j) {
12            int mid = i + (j-i)/2;
13            int temp = 0;
14            int d = 1;
15
16            for(int x : weights) {
17                temp += x;
18                if(temp > mid) {
19                    d++;
20                    temp = x;
21                }
22
23                if(d > days) break;
24            }
25
26            if(d <= days) {
27                ans = min(ans, mid);
28                j = mid-1;
29            } else i = mid+1;
30        }
31
32        return ans;
33    }
34};