// Last updated: 30/07/2026, 10:21:33
#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

// dp[pos][tight][isLeading][lastDigit][secondLastDigit]
// We use a pair: {count of valid numbers, sum of waviness}
pair<long long, long long> memo[16][2][2][11][11]; 
string numStr;

class Solution {
public:
    pair<long long, long long> dfs(int pos, bool tight, bool isLeading, int lastDigit, int secondLastDigit) {
        // Base case: If we've placed all digits
        if (pos == numStr.length()) {
            return {1, 0}; // 1 valid number formed, 0 extra waviness at the end
        }

        // Return cached result if already evaluated
        if (memo[pos][tight][isLeading][lastDigit][secondLastDigit].first != -1) {
            return memo[pos][tight][isLeading][lastDigit][secondLastDigit];
        }

        long long totalCount = 0;
        long long totalSum = 0;

        int limit = tight ? (numStr[pos] - '0') : 9;

        for (int digit = 0; digit <= limit; ++digit) {
            bool nextTight = tight && (digit == limit);
            bool nextLeading = isLeading && (digit == 0);

            int wavinessContribution = 0;
            
            // Check for peak or valley condition
            // Condition applies only if we have at least 2 structural digits before the current one
            if (!isLeading && lastDigit != 10 && secondLastDigit != 10) {
                if (lastDigit > secondLastDigit && lastDigit > digit) {
                    wavinessContribution = 1; // Peak
                } else if (lastDigit < secondLastDigit && lastDigit < digit) {
                    wavinessContribution = 1; // Valley
                }
            }

            // Move to the next digit state
            int nextLastDigit = nextLeading ? 10 : digit;
            int nextSecondLastDigit = nextLeading ? 10 : lastDigit;

            auto [nextCount, nextSum] = dfs(pos + 1, nextTight, nextLeading, nextLastDigit, nextSecondLastDigit);

            totalCount += nextCount;
            // Total sum = sum from subproblems + (contribution of current structure * number of valid branches it satisfies)
            totalSum += nextSum + (wavinessContribution * nextCount);
        }

        return memo[pos][tight][isLeading][lastDigit][secondLastDigit] = {totalCount, totalSum};
    }

    long long solve(long long X) {
        if (X < 100) return 0; // Any number with fewer than 3 digits has a waviness of 0
        numStr = to_string(X);
        
        // Initialize memoization array with -1
        memset(memo, -1, sizeof(memo));
        
        // Start DFS: position 0, tight=true, isLeading=true, lastDigit=10 (dummy), secondLastDigit=10 (dummy)
        return dfs(0, true, true, 10, 10).second;
    }

    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1 - 1);
    }
};