1class Solution {
2public:
3    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
4
5        sort(arr.begin(), arr.end());
6
7        arr[0] = 1;
8
9        for(int i = 1; i < arr.size(); i++) {
10            if(arr[i] > arr[i-1]+1) {
11                arr[i] = arr[i-1]+1;
12            }
13        }
14
15        return arr[arr.size()-1];
16    }
17};