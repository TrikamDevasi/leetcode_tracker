// Last updated: 30/07/2026, 10:24:57
class Solution {
public:
    int divide(int dividend, int divisor) {
        // Corner case: Handle 32-bit signed integer overflow
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        if (dividend == INT_MIN && divisor == 1) {
            return INT_MIN;
        }

        // Determine the sign of the result
        // True if the signs are different, meaning the result will be negative
        bool isNegative = (dividend < 0) ^ (divisor < 0);

        // Convert both numbers to negative to safely prevent overflow 
        // (INT_MIN converted to positive overflow a 32-bit int, but INT_MAX fits inside negative)
        long long absDividend = labs(dividend);
        long long absDivisor = labs(divisor);

        int quotient = 0;

        // Outer loop runs as long as the remaining dividend is greater than or equal to divisor
        while (absDividend >= absDivisor) {
            long long tempDivisor = absDivisor;
            int numShifts = 0;

            // Shift tempDivisor left (multiply by 2) until it exceeds absDividend
            while (absDividend >= (tempDivisor << 1)) {
                tempDivisor <<= 1;
                numShifts++;
            }

            // Add the corresponding binary power (2^numShifts) to the quotient
            quotient += (1 << numShifts);
            // Subtract the doubled divisor from the remaining dividend
            absDividend -= tempDivisor;
        }

        // Apply the correct sign to the result
        return isNegative ? -quotient : quotient;
    }
};