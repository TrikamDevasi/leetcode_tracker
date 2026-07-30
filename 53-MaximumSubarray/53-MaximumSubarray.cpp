// Last updated: 30/07/2026, 10:24:45
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur = nums[0],ans = nums[0];
        for(int i=1;i<nums.size();++i)
        ans=max(ans,cur=max(nums[i],cur+nums[i]));
        return ans;
    }
};