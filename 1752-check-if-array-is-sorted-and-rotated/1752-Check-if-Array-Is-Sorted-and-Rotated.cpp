class Solution {
public:
    bool check(vector<int>& nums) {
        int x = -1;

        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] < nums[i-1]) {
                x = i;
                break;
            }
        }

        if(x == -1) return true;

        int n = nums.size();

        for(int i = x; i < nums.size(); i++) {
            if(nums[i%n] > nums[(i+1)%n]) return false;
        }

        return true;
    }
};