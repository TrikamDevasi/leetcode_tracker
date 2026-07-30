// Last updated: 30/07/2026, 10:23:06
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_ones = 0;
        int current_ones = 0;
        
        for (int num : nums) {
            if (num == 1) {
                current_ones++;
            } else {
                max_ones = max(max_ones, current_ones);
                current_ones = 0;
            }
        }
        
        return max(max_ones, current_ones);
    }
};