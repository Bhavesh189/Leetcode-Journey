class Solution {
public:
    double minPrice(vector<int>& p, vector<int>& d) {
        double ans = 0;

        sort(p.begin(), p.end());
        sort(d.begin(), d.end());

        int n = p.size()-1, m = d.size()-1;

        while(n >= 0) {
            ans += (double)(p[n--]* (100-d[m--]))/100;

            if(m == -1) break;
        }

        while(n >= 0) ans += p[n--];

        return ans;
    }
};