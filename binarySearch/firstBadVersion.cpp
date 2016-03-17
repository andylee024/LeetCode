// Leet Code Problem 278

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if(n == 1) return 1;
        
        int firstIdx = 1;
        int endIdx = n;
        int pivot;
        
        while (firstIdx < endIdx){
            pivot = firstIdx + (endIdx - firstIdx)/2; // avoids overflow
            
            if (isBadVersion(pivot)){endIdx = pivot; continue;}
            firstIdx = pivot + 1;
        }
        
        return firstIdx;
    }
};
