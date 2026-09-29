class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        stack<int> st;

        int n = nums.size();
        vector<int> ans(n, 0);

        for(int i = n-1; i >= 0; i--) {
            while(!st.empty() && nums[st.top()] <= nums[i]) st.pop();
            ans[i] = st.empty() ? 0 : st.top()-i;
            st.push(i);
        }

        return ans;
    }
};