// Last updated: 30/07/2026, 10:21:50
class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int closest = nums[0];
        
        for (int num : nums) {
            if (abs(num) < abs(closest)) {
                closest = num;
            } else if (abs(num) == abs(closest)) {
                if (num > closest) {
                    closest = num;
                }
            }
        }
        
        return closest;
    }
};