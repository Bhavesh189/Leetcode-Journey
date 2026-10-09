class Solution {
public:
    int minInsertions(string s) {
        int ans = 0, need = 0;

        for(char ch : s) {
            if(ch == ')') {
                need--;

                if(need < 0) {
                    ans++;
                    need = 1;
                }
            } else {
                need += 2;
                if(need>2 && need&1) {
                    ans++;
                    need--;
                }
            }
        }

        return ans+need;
    }
};