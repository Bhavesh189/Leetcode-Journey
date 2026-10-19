class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int t) {
        int c = 0, a = 0;
        int n = nums.size();
        a = n;
        for(int x : nums) {
            if(x < t) c++;
            else if(x > t) a--;
        }

        vector<int> ans;

        for(int i = c; i < a; i++) ans.push_back(i);

        return ans;
    }
};