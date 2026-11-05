class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ans = 0;
        for(int x : arr1) {
            bool g = true;
            for(int y : arr2) {
                if(abs(x-y) <= d) {
                    g = false;
                    break;
                }
            }

            if(g) ans++;
        }

        return ans;
    }
};