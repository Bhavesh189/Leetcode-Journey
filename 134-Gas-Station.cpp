class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int ans = -1;

        int f = 0, t = 0;

        for(int i = 0; i < gas.size(); i++) {
            f += gas[i];
            f -= cost[i];

            if(f < 0) {
                ans = -1;
                f = 0;
            }
            else if(ans == -1) ans = i;
            t += gas[i];
            t -= cost[i];
        }

        if(t < 0) return -1;

        return ans;
    }
};