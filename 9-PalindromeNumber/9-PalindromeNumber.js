// Last updated: 30/07/2026, 10:25:30
/**
 * @param {number} x
 * @return {boolean}
 */
var isPalindrome = function(x) {
    // Negatives & trailing-zero non-zeros are never palindromes
    if (x < 0 || (x % 10 === 0 && x !== 0)) return false;

    let reversedHalf = 0;
    while (x > reversedHalf) {
        reversedHalf = reversedHalf * 10 + x % 10;
        x = Math.floor(x / 10);
    }

    // Even digits: 1221  → x=12, reversedHalf=12      → x === reversedHalf
    // Odd digits:  12321 → x=12, reversedHalf=123     → x === floor(123/10)
    return x === reversedHalf || x === Math.floor(reversedHalf / 10);
};
