class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp = arr;
        sort(arr.begin(), arr.end());

        unordered_map<int, int> mp;
        int i = 1;
        int prev = INT_MIN;

        for(int x : arr) {
            if(prev == x) continue;
            mp[x] = i++;
            prev = x;
        }

        for(int i = 0; i < arr.size(); i++) {
            temp[i] = mp[temp[i]];
        }

        return temp;
    }
};