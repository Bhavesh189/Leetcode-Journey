class Solution {
public:

    bool canAns(vector<int>& nums, int mid, int m, int k) {
        int q = 0, s = 0;
        for(int x : nums) {
            if(x <= mid) {
                s++;
            } else {
                s= 0;
            }

            if(s==k) {
                q++;
                s = 0;
            }
        }

        return q>=m;
    }

    int minDays(vector<int>& nums, int m, int k) {
        int n = nums.size(), s = 1, e = *max_element(nums.begin(), nums.end());

        int ans = INT_MAX;

        while(s <= e) {
            int mid = s + (e-s)/2;

            if(canAns(nums, mid, m, k)) {
                ans = min(ans, mid);
                e = mid-1;
            } else {
                s = mid+1;
            }
        }

        return ans==INT_MAX ? -1 : ans;
    }
};