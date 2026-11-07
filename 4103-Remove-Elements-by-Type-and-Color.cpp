class Solution {
public:
    bool canRemoveAll(vector<int>& types, vector<int>& colors,
                      vector<int>& groupSize) {
        vector<pair<pair<int, int>, int>> st;

        for (int i = 0; i < types.size(); i++) {
            int t = types[i];
            int c = colors[i];

            int need = groupSize[t];

            int cnt = 1;

            while (!st.empty() && st.back().first.first == t &&
                   st.back().first.second == c) {
                cnt+=st.back().second;
                st.pop_back();
                   }

            if(cnt == need) continue;

            else st.push_back({{t, c}, cnt});
        }

        return st.empty();
    }
};