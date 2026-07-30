// Last updated: 30/07/2026, 10:22:32
class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> result;
        
        // Process the array in pairs: nums[i] is frequency, nums[i+1] is value
        for (int i = 0; i < nums.size(); i += 2) {
            int freq = nums[i];
            int val = nums[i + 1];
            
            // Append 'val' to the result 'freq' times
            result.insert(result.end(), freq, val);
        }
        
        return result;
    }
};