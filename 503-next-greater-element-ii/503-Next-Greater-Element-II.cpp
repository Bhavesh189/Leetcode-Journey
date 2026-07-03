class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        unordered_map<int, int> mp;
        stack<int> st;

        for(int i = nums.size()-1; i >= 0; i--) st.push(nums[i]);
        vector<int> ans(nums.size());

        for(int i = nums.size()-1; i >= 0; i--) {
            while(!st.empty() && st.top() <= nums[i]) st.pop();
            mp[nums[i]] = st.empty() ? -1 : st.top();
            st.push(nums[i]);
            ans[i] = mp[nums[i]];
        }

        return ans;
    }
};