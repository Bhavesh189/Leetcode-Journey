class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int m1 = INT_MAX, m2 = INT_MAX;
        int c1, c2;
        c1 = c2 = 0;

        for(int x : nums) {
            if(x == m1) {
                c1++;
            } else if(x == m2) {
                c2++;
            } else if(c1 == 0) {
                m1 = x;
                c1 = 1;
            } else if(c2 == 0) {
                m2 = x;
                c2 = 1;
            } else {
                c1--;
                c2--;
            }
        }

        c1 = c2 = 0;

        for(int x : nums) {
            if(x==m1) c1++;
            if(x==m2) c2++;
        }

        int n = nums.size();
        
        if(c1>n/3 && c2>n/3) return {m1, m2};
        else if(c1>n/3) return {m1};
        else if(c2>n/3) return {m2};
        else return {};
    }
};