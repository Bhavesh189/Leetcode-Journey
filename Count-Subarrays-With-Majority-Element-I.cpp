1class Solution {
2public:
3    int countMajoritySubarrays(vector<int>& nums, int target) {
4        int n = nums.size();
5
6        vector<int> pref(n+1, 0);
7        int ans = 0;
8
9        for(int i = 0; i < n; i++) {
10            pref[i+1] = pref[i]+(nums[i]==target);
11        }
12
13        for(int i = 0; i < n; i++) {
14            for(int j = i; j < n; j++) {
15                int l = j-i+1;
16                int t = pref[j+1]-pref[i];
17
18                if(t > l/2) ans++;
19            }
20        }
21
22        return ans;
23    }
24};