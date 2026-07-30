// Last updated: 30/07/2026, 10:25:31
function longestPalindrome(s) {
    let start = 0, maxLen = 1;

    function expand(l, r) {
        while (l >= 0 && r < s.length && s[l] === s[r]) {
            l--;
            r++;
        }
        return [l + 1, r - 1]; // last valid bounds
    }

    for (let i = 0; i < s.length; i++) {
        // Odd length palindrome: "aba"
        const [l1, r1] = expand(i, i);
        // Even length palindrome: "abba"
        const [l2, r2] = expand(i, i + 1);

        for (const [l, r] of [[l1, r1], [l2, r2]]) {
            if (r - l + 1 > maxLen) {
                maxLen = r - l + 1;
                start = l;
            }
        }
    }

    return s.slice(start, start + maxLen);
}