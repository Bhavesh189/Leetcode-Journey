class Solution {
public:

    long long solve(string& word, int k) {
        int a, e, i, o, u;
        a = e = i = o = u = 0;
        long long ans = 0, c = 0;

        int l = 0;

        for (int r = 0; r < word.size(); r++) {
            if (word[r] == 'a')
                a++;
            else if (word[r] == 'e')
                e++;
            else if (word[r] == 'i')
                i++;
            else if (word[r] == 'o')
                o++;
            else if (word[r] == 'u')
                u++;
            else
                c++;

            bool mila = a && e && i && o && u;

            while (l < r && mila && c >= k) {
                ans += (word.size()-r);
                char ch = word[l++];
                if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' ||
                    ch == 'u') {
                    if (ch == 'a')
                        a--;
                    else if (ch == 'e')
                        e--;
                    else if (ch == 'i')
                        i--;
                    else if (ch == 'o')
                        o--;
                    else
                        u--;
                    mila = a && e && i && o && u;
                } else {
                    c--;
                }
            }
        }

        return ans;
    }

    long long countOfSubstrings(string word, int k) {
        return solve(word, k) - solve(word, k+1);
    }
};