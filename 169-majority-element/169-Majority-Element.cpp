class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int le = -1;
        int f = 0;

        for(int x : nums) {
            if(f==0) {
                le = x;
                f = 0;
            }
            if(x == le) f++;
            else f--;
        }

        return le;
    }
};