class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& nums) {
        vector<vector<int>> adj(n);

        vector<int> inDegree(n, 0);
        int m = nums.size();
        for(int i = 0; i < m; i++) {
            adj[nums[i][1]].push_back(nums[i][0]), inDegree[nums[i][0]]++;
        }

        queue<int> q;
        int cnt = 0;

        for(int i = 0; i < n; i++) if(!inDegree[i]) q.push(i);

        while(!q.empty()) {
            cnt++;

            int front = q.front();
            q.pop();

            for(int x : adj[front]) if(--inDegree[x] == 0) q.push(x);
        }

        return cnt == n;
    }
};