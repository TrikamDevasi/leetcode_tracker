// Last updated: 30/07/2026, 10:21:39
class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n);
        
        int leftSum = 0;
        int rightSum = 0;
        
        // Calculate the total sum of the array
        for (int num : nums) {
            rightSum += num;
        }
        
        // Compute the absolute difference for each index
        for (int i = 0; i < n; ++i) {
            // Remove the current element from rightSum to get the sum of elements to its right
            rightSum -= nums[i];
            
            // Calculate the absolute difference
            answer[i] = abs(leftSum - rightSum);
            
            // Add the current element to leftSum for the next iterations
            leftSum += nums[i];
        }
        
        return answer;
    }
};