// Last updated: 30/07/2026, 10:22:58
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total_sum = 0;
        for (int num : nums) {
            total_sum += num;
        }
        
        int left_sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            // total_sum - left_sum - nums[i] yields the right_sum strictly to the right of index i
            if (left_sum == total_sum - left_sum - nums[i]) {
                return i;
            }
            left_sum += nums[i];
        }
        
        return -1;
    }
};