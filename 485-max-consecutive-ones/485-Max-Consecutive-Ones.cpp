class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;

        int sum = 0;

        for(int x : nums) {
            if(x == 0) sum = 0;
            else sum++;

            ans = max(ans, sum);
        }

        return ans;
    }
};