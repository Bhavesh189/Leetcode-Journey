class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int f,s,t;
        int nf,ns,nt;
        f = s = t = -1111;
        nf = ns = nt = 1111;

        for(int x : nums) {
            if(x > f) {
                t = s;
                s = f;
                f = x;
            } else if(x > s) {
                t = s;
                s = x;
            } else if(x > t) {
                t = x;
            }

            
            if(x < nf) {
                nt = ns;
                ns = nf;
                nf = x;
            } else if(x < ns) {
                nt = ns;
                ns = x;
            } else if(x < nt) {
                nt = x;
            }

            
        }

        int ans = nf*ns*f;

        return max(f*s*t, ans);
    }
};