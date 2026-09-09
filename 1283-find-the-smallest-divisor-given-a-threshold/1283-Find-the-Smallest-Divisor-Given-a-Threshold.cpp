class Solution {
public:
    int smallestDivisor(vector<int>& nums, int t) {
        int ans = INT_MAX;
        int st = 1, e = *max_element(nums.begin(), nums.end());

        while(st<=e) {
            int mid = st + (e-st)/2;
            int s = 0;
            bool bx = true;

            for(int x : nums) {
                s += (x+mid-1)/mid;
                if(s > t) {
                    bx = false;
                    break;
                }
            }

            if(bx) {
                ans = min(ans, mid);
                e = mid-1;
            } else {
                st = mid+1;
            }
        }

        return ans;
    }
};