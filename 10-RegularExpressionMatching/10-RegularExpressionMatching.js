// Last updated: 30/07/2026, 10:25:22
/**
 * @param {string} s
 * @param {string} p
 * @return {boolean}
 */
var isMatch = function(s, p) {
    const m = s.length, n = p.length;

    // dp[i][j] = does s[0..i-1] match p[0..j-1]?
    const dp = Array.from({ length: m + 1 }, () => Array(n + 1).fill(false));
    dp[0][0] = true;

    // Empty string can match patterns like a*, a*b*, a*b*c* ...
    for (let j = 2; j <= n; j++) {
        if (p[j - 1] === '*') dp[0][j] = dp[0][j - 2];
    }

    for (let i = 1; i <= m; i++) {
        for (let j = 1; j <= n; j++) {
            if (p[j - 1] === '*') {
                dp[i][j] = dp[i][j - 2];                           // zero occurrences of x*
                if (p[j - 2] === '.' || p[j - 2] === s[i - 1]) {  // char matches preceding element
                    dp[i][j] = dp[i][j] || dp[i - 1][j];           // use one more occurrence
                }
            } else if (p[j - 1] === '.' || p[j - 1] === s[i - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
        }
    }

    return dp[m][n];
};
