// Last updated: 30/07/2026, 10:23:11
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long first = -2147483649LL;
        long long second = -2147483649LL;
        long long third = -2147483649LL;
        
        for (int num : nums) {
            if (num == first || num == second || num == third) {
                continue;
            }
            
            if (num > first) {
                third = second;
                second = first;
                first = num;
            } else if (num > second) {
                third = second;
                second = num;
            } else if (num > third) {
                third = num;
            }
        }
        
        return third == -2147483649LL ? first : third;
    }
};