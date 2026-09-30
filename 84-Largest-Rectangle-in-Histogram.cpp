class Solution {
public:
    int largestRectangleArea(vector<int>& nums) {
        int n = nums.size();
        vector<int> ls(n, -1);
        vector<int> rs(n, -1);

        stack<int> st;

        for(int i = 0; i < n; i++) {
            while(!st.empty() && nums[st.top()] >= nums[i]) st.pop();
            ls[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i = n-1; i >= 0; i--) {
            while(!st.empty() && nums[st.top()] >= nums[i]) st.pop();
            rs[i] = st.empty() ? n : st.top();

            st.push(i);
        }

        int ans = 0;

        for(int i = 0; i < n; i++) {
            int l = ls[i];
            int r = rs[i];

            int width = r-l-1;

            ans = max(ans, nums[i]*width);
        }

        return ans;
    }
};