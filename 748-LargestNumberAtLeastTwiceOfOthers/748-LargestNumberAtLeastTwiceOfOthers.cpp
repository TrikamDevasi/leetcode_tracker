// Last updated: 30/07/2026, 10:22:52
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int first = -1;
        int second = -1;
        int max_index = -1;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > first) {
                second = first;
                first = nums[i];
                max_index = i;
            } else if (nums[i] > second) {
                second = nums[i];
            }
        }
        
        return (first >= 2 * second) ? max_index : -1;
    }
};