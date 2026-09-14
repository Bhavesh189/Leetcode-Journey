class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](vector<int>& a, vector<int>& b) {
            return a[1]>b[1];
        });
        int c = 0;
        int ans = 0;

        for(vector<int> x : boxTypes) {
            if(c+x[0] > truckSize) return ans+(truckSize-c)*(x[1]);
            ans += x[1]*x[0];
            c+=x[0];
            if(c==truckSize) return ans;
        }

        return ans;
    }
};