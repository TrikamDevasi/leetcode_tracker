// Last updated: 30/07/2026, 10:22:19
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        partial_sum(nums.begin(),nums.end(),nums.begin());
        return nums;
    }
};