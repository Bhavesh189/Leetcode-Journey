class Solution {
public:
    vector<int> grayCode(int n) {
        int t = pow(2, n);
        vector<int> ans;

        for(int i = 0; i < t; i++) {
            ans.push_back((i>>1)^i);
        }

        return ans;
    }
};