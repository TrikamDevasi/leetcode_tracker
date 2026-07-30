// Last updated: 30/07/2026, 10:24:44
class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;
        int i = s.size() - 1;

        // Step 1: Skip all trailing spaces
        while (i >= 0 && s[i] == ' ') {
            i--;
        }

        // Step 2: Count characters of the last word
        while (i >= 0 && s[i] != ' ') {
            length++;
            i--;
        }

        // Step 3: Return the length of the last word
        return length;
    }
};