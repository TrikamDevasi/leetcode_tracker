// Last updated: 30/07/2026, 10:22:27
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int c=0;
        for(int n : nums) c+= to_string(n).size()%2==0;
        return c;
    }
};