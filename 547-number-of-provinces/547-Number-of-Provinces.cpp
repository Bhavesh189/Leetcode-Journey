class Solution {
public:

    void dfs(int node, int n, vector<bool>& vis, vector<vector<int>>& graph) {
        if(vis[node]) return;

        vis[node] = true;

        for(int i = 0; i < n; i++) {
            if(graph[node][i]) {
                dfs(i, n, vis, graph);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& graph) {
        int ans = 0;

        int m = graph.size(), n = graph[0].size();
        vector<bool> vis(n, false);

        for(int node = 0; node < n; node++) {
            if(!vis[node]) {
                dfs(node, n, vis, graph);
                ans++;
            }
        }

        return ans;
    }
};