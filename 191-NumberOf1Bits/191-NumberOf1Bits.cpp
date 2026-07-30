// Last updated: 30/07/2026, 10:23:48
class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        
        while (n != 0) {
            // Clears the lowest set bit
            n = n & (n - 1);
            count++;
        }
        
        return count;
    }
};