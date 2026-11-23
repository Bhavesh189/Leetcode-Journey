class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        for (int x : nums) {
            mp[x]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        unordered_map<int, bool> vis;

        for (int x : nums) {
            if (vis[x])
                continue;
            vis[x] = true;

            pq.push({mp[x], x});

            if (pq.size() > k)
                pq.pop();
        }

        vector<int> ans;

        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};