// Last updated: 30/07/2026, 10:24:34
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        for(int x:nums)
        if(i<2||x>nums[i-2]) nums[i++]=x;
        return i;
    }
};