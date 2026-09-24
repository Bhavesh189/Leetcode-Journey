class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int i = 0;
        for(int x : nums) {
            int add = 0;

            while(x > 0) {
                add += x%10;
                x/=10;
            }

            if(add == i) return i;
            i++;
        }

        return -1;
    }
};