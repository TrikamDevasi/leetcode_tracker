// Last updated: 30/07/2026, 10:25:23
/**
 * @param {string} s
 * @return {number}
 */
var myAtoi = function(s) {
    const INT_MAX = 2 ** 31 - 1;  // 2147483647
    const INT_MIN = -(2 ** 31);   // -2147483648

    let i = 0;
    const n = s.length;

    // Step 1: Skip leading whitespace
    while (i < n && s[i] === ' ') i++;

    // Step 2: Determine sign
    let sign = 1;
    if (i < n && (s[i] === '+' || s[i] === '-')) {
        if (s[i] === '-') sign = -1;
        i++;
    }

    // Step 3: Read digits with overflow check
    let result = 0;
    const limit = Math.floor(INT_MAX / 10); // 214748364

    while (i < n && s[i] >= '0' && s[i] <= '9') {
        const digit = s.charCodeAt(i) - 48; // faster than parseInt

        // Check overflow BEFORE updating result
        if (result > limit || (result === limit && digit > (sign === 1 ? 7 : 8))) {
            return sign === 1 ? INT_MAX : INT_MIN;
        }

        result = result * 10 + digit;
        i++;
    }

    return sign * result;
};
