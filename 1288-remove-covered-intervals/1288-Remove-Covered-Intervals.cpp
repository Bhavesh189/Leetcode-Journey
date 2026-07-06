class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            if(a[0] == b[0]) {
                return a[1] > b[1];
            } else return a[0] < b[0];
        });

        vector<vector<int>> merge;
        int ans = 0;

        merge.push_back(intervals[0]);

        for(int i = 1; i < n; i++) {
            int a = merge.back()[0];
            int b = merge.back()[1];
            int c = intervals[i][0];
            int d = intervals[i][1];
            if(c >= a && b >= d) {
                continue;
            } else {
                merge.push_back(intervals[i]);
            }
        }

        return merge.size();
    }
};