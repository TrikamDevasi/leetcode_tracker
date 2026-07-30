// Last updated: 30/07/2026, 10:21:55
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans;
        ans.reserve(nums.size()); // Optimize memory allocation
        
        // Pass 1: Collect all elements less than pivot
        for (int num : nums) {
            if (num < pivot) ans.push_back(num);
        }
        
        // Pass 2: Collect all elements equal to pivot
        for (int num : nums) {
            if (num == pivot) ans.push_back(num);
        }
        
        // Pass 3: Collect all elements greater than pivot
        for (int num : nums) {
            if (num > pivot) ans.push_back(num);
        }
        
        return ans;
    }
};