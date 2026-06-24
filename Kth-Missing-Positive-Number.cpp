1class Solution {
2public:
3    int findKthPositive(vector<int>& arr, int k) {
4        int i = 0, j = arr.size()-1;
5
6        while(i <= j) {
7            int mid = i + (j-i)/2;
8
9            int d = arr[mid]- (mid+1);
10
11            if(d >= k) j = mid-1;
12            else {
13                i = mid+1;
14            }
15        }
16        
17        return i+k;
18    }
19};