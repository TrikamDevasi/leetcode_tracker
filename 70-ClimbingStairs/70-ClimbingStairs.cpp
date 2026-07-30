// Last updated: 30/07/2026, 10:24:39
class Solution {
public:
    int climbStairs(int n) {
        long long a = 1, b = 1; 
        while (n--) {
            a += std::exchange(b, a);
        }
        return b;
    }
};