// Last updated: 30/07/2026, 10:21:44
class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> distinct_nums;
        
        for (int num : nums) {
            distinct_nums.insert(num);
            
            int reversed_num = 0;
            int temp = num;
            while (temp > 0) {
                reversed_num = reversed_num * 10 + (temp % 10);
                temp /= 10;
            }
            distinct_nums.insert(reversed_num);
        }
        
        return distinct_nums.size();
    }
};