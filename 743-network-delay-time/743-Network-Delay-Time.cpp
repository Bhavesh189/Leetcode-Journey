class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<int>> graph(n + 1, vector<int>(n + 1, -1));

        for (const auto& t : times) {
            int t1 = t[0], t2 = t[1], t3 = t[2];

            graph[t1][t2] = t3;
        }

        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        pq.push({0, k});

        while (!pq.empty()) {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (d > dist[u])
                continue;

            for (int v = 0; v <= n; v++) {
                int wt = graph[u][v];
                if (wt == -1)
                    continue;

                if (d + wt < dist[v]) {
                    dist[v] = d + wt;
                    pq.push({dist[v], v});
                }
            }
        }

        int ans = *max_element(dist.begin()+1, dist.end());

        return ans == INT_MAX ? -1 : ans;
    }
};