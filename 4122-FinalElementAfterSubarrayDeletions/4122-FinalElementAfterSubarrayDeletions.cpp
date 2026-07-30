// Last updated: 30/07/2026, 10:21:32
class Solution {
public:
    int finalElement(vector<int>& nums) {
        return max(nums.front(), nums.back());
    }
};