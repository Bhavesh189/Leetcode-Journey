class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int c = INT_MIN, v = 1;

        for(int x : nums) {
            if(c == x) v++;
            else if(v-1 == 0) {
                c = x;
                v = 1;
            } else v--;
        }

        return c;
    }
};