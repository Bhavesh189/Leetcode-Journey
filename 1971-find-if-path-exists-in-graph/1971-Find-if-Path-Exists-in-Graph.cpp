class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, int ans,
             vector<bool>& visited) {
        visited[node] = true;
        if (node == ans)
            return true;
        bool res = false;

        for (int x : adj[node]) {
            if (!visited[x])
                res |= dfs(x, adj, ans, visited);
            if (res)
                return true;
        }

        return res;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source,
                   int destination) {
        vector<bool> visited(n);
        vector<vector<int>> adj(n);

        for (auto j : edges) {
            int u = j[0];
            int v = j[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return dfs(source, adj, destination, visited);
    }
};