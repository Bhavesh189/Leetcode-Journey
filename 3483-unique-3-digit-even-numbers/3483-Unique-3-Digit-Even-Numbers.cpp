class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int ans = 0;

        vector<int> freq(10, 0);

        for(int x : digits) freq[x]++;

        for(int i = 100; i < 1000; i+=2) {
            int d1, d2, d3;

            int q = i;
            
            d1 = i%10;
            i/=10;
            d2 = i%10;
            i/=10;
            d3 = i%10;

            i = q;

            vector<int> f(10, 0);
            f[d1]++;
            f[d2]++;
            f[d3]++;

            bool x = true;

            for(int j = 0; j < 10; j++) if(f[j] > freq[j]) {
                x = false;
                break;
            }

            if(x) ans++;
        }

        return ans;
    }
};