class Solution {
public:
    string removeKdigits(string nums, int k) {
        int n = nums.size();

        stack<char> st;

        for(int i = 0; i < n; i++) {
            char x = nums[i];
            while(!st.empty() && k>0 && st.top() > x) {
                st.pop();
                k--;
            }

            st.push(x);
        }

        while(k>0) {
            st.pop();
            k--;
        }


        string ans = "";
        
        while(!st.empty()) {
            ans += st.top(); st.pop();
        }

        n = ans.size()-1;
        while(n >= 0 && ans[n--]=='0') ans.pop_back();

        reverse(ans.begin(), ans.end());



        return ans=="" ? "0" : ans;
    }
};