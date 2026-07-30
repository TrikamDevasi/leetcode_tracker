// Last updated: 30/07/2026, 10:24:12
class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;
        
        while (left < right) {
            // Skip non-alphanumeric characters from the left
            if (!isalnum(s[left])) {
                left++;
            } 
            else if (!isalnum(s[right])) {
                right--;
            } 
            else {
                if (tolower(s[left]) != tolower(s[right])) {
                    return false;
                }
                left++;
                right--;
            }
        }
        
        return true;
    }
};