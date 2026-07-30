class Solution {
public:
    int minimumPushes(string s) {

        if(s.size() <= 8) return s.size();
        int c = 0;

        for(int i = 0; i < s.size(); i++) c += (i/8);

        return s.size()+c;
    }
};