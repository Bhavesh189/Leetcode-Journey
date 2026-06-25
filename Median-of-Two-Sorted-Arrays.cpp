1class Solution {
2public:
3    vector<double> merge(vector<int>& nums1, vector<int>& nums2) {
4        int m = nums1.size(), n = nums2.size();
5
6        vector<double> ans(m+n, 0);
7
8        int i = 0, j = 0, k = 0;
9
10        while(i < m || j < n)
11        if(i < m && j < n) if(nums1[i] < nums2[j]) ans[k++] = nums1[i++];
12        else ans[k++] = nums2[j++];
13        else if(i < m) ans[k++] = nums1[i++];
14        else ans[k++] = nums2[j++];
15        
16        return ans;
17    }
18
19    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
20        vector<double> nums = merge(nums1, nums2);
21
22        int n = nums.size();
23
24        if(n&1) return nums[n/2];
25        else return (nums[(n-1)/2]+nums[((n-1)/2) +1])/2.0;
26    }
27};