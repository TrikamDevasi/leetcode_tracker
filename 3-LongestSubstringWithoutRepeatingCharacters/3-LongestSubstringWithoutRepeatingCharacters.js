// Last updated: 30/07/2026, 10:25:39
function lengthOfLongestSubstring(s) {
    const charIndex = new Map();
    let left = 0;
    let maxLen = 0;

    for (let right = 0; right < s.length; right++) {
        const char = s[right];

        // If char is in the window, shrink left past its last position
        if (charIndex.has(char) && charIndex.get(char) >= left) {
            left = charIndex.get(char) + 1;
        }

        charIndex.set(char, right);
        maxLen = Math.max(maxLen, right - left + 1);
    }

    return maxLen;
}