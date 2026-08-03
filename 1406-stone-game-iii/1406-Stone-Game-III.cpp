class Solution {
public:
    string stoneGameIII(vector<int>& nums) {
        int n = nums.size();

        int n1, n2, n3;
        n1 = n2 = n3 = 0;

        for(int i = n-1; i >= 0; i--) {
            int x = nums[i] - n1;
            int y, z;
            y = z = INT_MIN;

            if(i+1 < n) y = nums[i] + nums[i+1] - n2;
            if(i+2 < n) z = nums[i] + nums[i+1] + nums[i+2] - n3;

            int curr = max({x, y, z});

            n3 = n2;
            n2 = n1;
            n1 = curr;
        }

        if(n1 == 0) return "Tie";
        else if(n1 < 0) return "Bob";
        else return "Alice";
    }
};