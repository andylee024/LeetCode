// LeetCode 123 - Stock III

// Solution Idea: 
// Maintain 2 arrays maxLeft and maxRight representing 1st and 2nd transactions respectively. 

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        if (prices.size() < 1)
            return 0;
            
        int maxProfit_left = 0;
        int maxProfit_right = 0; 
        
        int n = prices.size();
        int lowest = prices[0];
        int largest = prices[n-1];
        int maxLeft[n];
        int maxRight[n];
        maxLeft[0] = 0;
        maxRight[n-1] = 0;
        
        // maxLeft(i) = best profit for array[:i]
        for (int i=0; i<n; i++){
            int profit = prices[i] - lowest;
            if (prices[i] < lowest)
                lowest = prices[i];
            if (profit > maxProfit_left)
                maxProfit_left = profit;
            maxLeft[i] = maxProfit_left;
        }
        
        // maxRight(i) = best profit for array[i:]
        for (int j=n-1; j>=0; j--){
            int profit = largest - prices[j];
            if (prices[j] > largest)
                largest = prices[j];
            if (profit > maxProfit_right)
                maxProfit_right = profit;
            maxRight[j] = maxProfit_right;
        }
        
        // calculate maximum profit
        int maxProfit = maxLeft[n-1];
        for (int i=0; i<n-1; i++){
            int profit = maxLeft[i] + maxRight[i+1];
            if (profit > maxProfit)
                maxProfit = profit;
        }
        
        return maxProfit;    
        
        
        
        
    }
};
