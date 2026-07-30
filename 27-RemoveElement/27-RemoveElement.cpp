// Last updated: 30/07/2026, 10:25:00
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        for(int x:nums) if (x!=val) nums[i++]=x;
        return i;
    }
};