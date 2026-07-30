// Last updated: 30/07/2026, 10:24:05
class Solution {
public:
    string reverseWords(string s) {
        // 1. Reverse the whole string
        reverse(s.begin(), s.end());

        int n = s.size();
        int idx = 0; // Pointer to place the next valid character

        for (int start = 0; start < n; ++start) {
            if (s[start] != ' ') {
                // Add a space before the next word (but not before the first word)
                if (idx != 0) s[idx++] = ' ';

                // Find the end of the current word
                int end = start;
                while (end < n && s[end] != ' ') end++;

                // 2. Reverse the individual word in its current position
                // We reverse the word characters BEFORE shifting them
                reverse(s.begin() + start, s.begin() + end);

                // 3. Move the reversed word to the 'idx' position
                while (start < end) {
                    s[idx++] = s[start++];
                }
            }
        }
        
        // Trim the tail of the string that contains old characters/spaces
        s.erase(s.begin() + idx, s.end());
        return s;
    }
};