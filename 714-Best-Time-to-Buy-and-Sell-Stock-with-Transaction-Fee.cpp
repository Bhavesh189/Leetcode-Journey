class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int profit = 0, buy = INT_MIN;

        for(int& p : prices) {
            buy = max(buy, profit-p);
            profit = max(profit, p+buy-fee);
        }

        return profit;
    }
};