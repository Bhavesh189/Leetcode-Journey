class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        unordered_map<int, int> mp;

        for (int i = 0; i < s.size(); i++) {
            mp[s[i]] = i;
        }

        int j = 0;
        int st = 0;

        for (int i = 0; i < s.size(); i++) {
            j = max(j, mp[s[i]]);

            if (j == i) {
                ans.push_back(i - st + 1);
                st = i + 1;
            }
        }

        return ans;
    }
};