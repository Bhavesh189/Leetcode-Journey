class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num(nums.begin(), nums.end());

        int ans = 0;

        for(int x : num) {
            int c = 1;

            if(num.find(x-1) == num.end()) {
                while(num.count(x+1)) {
                    c += 1;
                    x += 1;
                }
            }

            ans = max(ans, c);
        }

        return ans;
    }
};