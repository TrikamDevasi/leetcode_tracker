// Last updated: 30/07/2026, 10:23:26
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto i:nums){
            if(mp[i]==0){
                mp[i]=1;
            }else
            {
                return i;
            }
        }
        return -1;
    }
};