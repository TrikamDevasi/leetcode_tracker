// Last updated: 07/09/2026, 10:20:39
1class Solution {
2public:
3    int divide(int dividend, int divisor) {
4        if (dividend == INT_MIN && divisor == -1) {
5            return INT_MAX;
6        }
7        if (dividend == INT_MIN && divisor == 1) {
8            return INT_MIN;
9        }
10
11     
12        bool isNegative = (dividend < 0) ^ (divisor < 0);
13
14        long long absDividend = labs(dividend);
15        long long absDivisor = labs(divisor);
16
17        int quotient = 0;
18
19        while (absDividend >= absDivisor) {
20            long long tempDivisor = absDivisor;
21            int numShifts = 0;
22
23            while (absDividend >= (tempDivisor << 1)) {
24                tempDivisor <<= 1;
25                numShifts++;
26            }
27
28            quotient += (1 << numShifts);
29
30            absDividend -= tempDivisor;
31        }
32
33        return isNegative ? -quotient : quotient;
34    }
35};