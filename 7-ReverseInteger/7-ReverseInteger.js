// Last updated: 30/07/2026, 10:25:26
/**
 * @param {number} x
 * @return {number}
 */
var reverse = function(x) {
    const INT_MAX = 2 ** 31 - 1;  // 2147483647
    const INT_MIN = -(2 ** 31);   // -2147483648

    const sign = x >= 0 ? 1 : -1;
    let xAbs = Math.abs(x);
    let rev = 0;

    while (xAbs !== 0) {
        const digit = xAbs % 10;
        xAbs = Math.floor(xAbs / 10);  // JS has no // operator

        // Overflow check BEFORE updating rev
        if (rev > Math.floor(INT_MAX / 10) ||
           (rev === Math.floor(INT_MAX / 10) && digit > 7)) {
            return 0;
        }

        rev = rev * 10 + digit;
    }

    return sign * rev;
};
