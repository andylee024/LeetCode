class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        if (nums.size() == 0){return 0;} // edge case: 0 length vector
        int best, candidate; 
        int ans = 0;
        
        // initialize table of optimal sequences
        int n = nums.size();
        int T[n];
        T[n-1] = 1;
        ans = T[n-1];
        
        /* This double for loop calculates entries T[i], where T[i] is longest subsequence starting with element i. */
        for (int i = n-2; i>=0; i--){
            best = 0;
            candidate = 1;
            for (int j = i+1; j<n; j++){
                if (nums[i] < nums[j]){candidate = 1 + T[j];}
                if (candidate > best){best = candidate;}
            }
            T[i] = best;
            
            // track longest increasing subsequence
            if (T[i] > ans){ans = T[i];}
        }
        return ans;
    }
};
