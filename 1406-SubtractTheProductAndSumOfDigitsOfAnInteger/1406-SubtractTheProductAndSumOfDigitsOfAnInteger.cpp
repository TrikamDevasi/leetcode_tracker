// Last updated: 30/07/2026, 10:22:28
class Solution {
public:
    int subtractProductAndSum(int n) {
        int product = 1, sum = 0;
        while (n > 0) {
            int digit = n % 10;
            product *= digit;
            sum += digit;
            n /= 10;
        }
        return product - sum;
    }
};