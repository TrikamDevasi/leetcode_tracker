// Last updated: 30/07/2026, 10:21:35
class Solution {
public:
    int countKeyChanges(string s) {
        int changes = 0;
        
        for (int i = 0; i < s.length() - 1; i++) {
            if (tolower(s[i]) != tolower(s[i + 1])) {
                changes++;
            }
        }
        
        return changes;
    }
};