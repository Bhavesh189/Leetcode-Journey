class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        int s = 0, e = n-1;

        while(s <= e) {
            int mid = s + (e-s)/2;

                if(mid&1) mid = mid-1;

                if(nums[mid] == nums[mid+1]) {
                    s = mid+2;
                }
                else {
                    e = mid-1;
                }
        }

        return nums[s];
    }
};