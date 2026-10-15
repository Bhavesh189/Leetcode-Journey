class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> ans;

        for(string &x : strs) {
            string t = "";

            vector<int> freq(26, 0);
            
            for(char ch : x) {
                freq[ch-'a']++;
            }

            for(int z : freq) t += to_string(z)+'.';

            mp[t].push_back(x);
        }

        for(auto it : mp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};