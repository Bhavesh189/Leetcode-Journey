class Solution {
public:
    int minOperations(string s1, string s2) {
        int n = s1.size();

        long long edges = 0, plus = 0, minus = 0;
        vector<bool> covered(n, false);

        for (int i = 0; i < n; i++) {
            char a = s1[i], b =s2[i];
            if (a == '0' && b == '1') {
                plus++;
            } else if (a == '1' && b == '0') {
                minus++;
                if (!covered[i]) {
                    if (i + 1 < n) {
                        edges++;
                        covered[i] = covered[i + 1] = true;
                    } else if (i - 1 >= 0) {
                        edges++;
                        covered[i] = true;
                    } else {
                        return -1;
                    }
                }
            }
        }
        return (int)(3 * edges + plus - minus);
    }
};