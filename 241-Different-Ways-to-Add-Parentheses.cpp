class Solution {
public:

    int eval(int x, int y, char sign) {
        if(sign == '*') return x*y;
        if(sign == '+') return x+y;
        if(sign == '-') return x-y;
        if(sign == '/') return x/y;

        return -1;
    }

    vector<int> diffWaysToCompute(string exp) {
        int n = exp.size();
        vector<int> ans;
        bool isStarting = true;

        for(int i = 0; i < n; i++) {
            if(!isdigit(exp[i])) {
                isStarting = false;
                vector<int> left = diffWaysToCompute(exp.substr(0, i));
                vector<int> right = diffWaysToCompute(exp.substr(i+1));

                for(int x : left) {
                    for(int y : right) {
                        ans.push_back(eval(x, y, exp[i]));
                    }
                }
            }
        }

        if(isStarting) ans.push_back(stoi(exp));
        return ans;
    }
};