// LeetCode 121 - Best Time to Buy and Sell Stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        // edge case
        if (prices.size() <= 1){return 0;}
        
        // algorithm
        int min = prices[0];
        int max_profit = 0;
        int profit;
        for (int i=1;i<prices.size();i++){
            if (prices[i] < min){min = prices[i];}
            profit = prices[i] - min;
            if (max_profit < profit){max_profit = profit;}
        }
        return max_profit;
        
        
    }
};
