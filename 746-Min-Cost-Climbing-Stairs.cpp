class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int p1, p2;
        p1 = p2 = 0;
        int n = cost.size();
        // vector<int> dp(n+1, 0);

        for(int i = 2; i < n; i++) {
            int x = min(p1+cost[i-1], p2+cost[i-2]);
            p2 = p1;
            p1 = x;
        }

        return min(p1+cost[n-1], p2+cost[n-2]);;
    }
};