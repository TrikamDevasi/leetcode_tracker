// Last updated: 30/07/2026, 10:22:04
class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int min_distance = INT_MAX;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == target) {
                min_distance = min(min_distance, abs(i - start));
            }
        }
        
        return min_distance;
    }
};