class Solution {
public:
    int maximumSwap(int num) {
        vector<int> digits(10, -1);

        string st = to_string(num);
        int n = st.size();

        for (int i = 0; i < n; i++) {
            digits[st[i] - '0'] = i;
        }

        for (int i = 0; i < n; i++) {
            for (int d = 9; d > st[i] - '0'; d--) {
                if ((digits[d] > i) && (st[digits[d]] > (st[i] - '0'))) {
                    swap(st[i], st[digits[d]]);
                    return stoi(st);
                }
            }
        }

        return num;
    }
};