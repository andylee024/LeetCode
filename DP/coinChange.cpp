// Leet Code - 322

#include <algorithm>
#include <climits>

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        vector<int> T(amount+1,-1);
        std::sort(coins.begin(), coins.end()); // sort array ascending 
        
        // initialize table
        T[0] = 0;
        for (auto e: coins){
            if (e <= amount)
                T[e]=1;
        }

        // populate table
        for (int curAmt=coins[0]+1; curAmt<=amount; curAmt++){
            int minimum = INT_MAX;
            for (auto e: coins){
                if (e > curAmt)
                    break;
                else{
                    if (T[curAmt-e] != -1){ 
                        int result = T[curAmt-e] + 1;
                        if (result < minimum)
                            minimum = result;
                    }
                }
            T[curAmt] =  (minimum != INT_MAX) ? minimum : -1;
            }
        }
        return T[amount];
    }
};
