// Last updated: 30/07/2026, 10:24:11
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        return accumulate(nums.begin(),nums.end(),0,bit_xor<int>());
    }
};