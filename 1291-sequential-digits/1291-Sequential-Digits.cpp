class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string st = "123456789";

        vector<int> ans;

       for(int i = 0; i < 9; i++) {
            for(int j = i; j < 9; j++) {
                string s = st.substr(i, j-i+1);
                int a = stoi(s);
                if(a >= low && a <= high) ans.push_back(a);
            }
       }

       sort(ans.begin(), ans.end());

        return ans;
    }
};