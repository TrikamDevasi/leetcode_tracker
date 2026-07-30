// Last updated: 30/07/2026, 10:22:02
class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        int sIndex = 0;
        int sLength = s.length();
        
        for (const string& word : words) {
            for (char ch : word) {
                if (sIndex >= sLength || s[sIndex] != ch) {
                    return false;
                }
                sIndex++;
            }
            if (sIndex == sLength) {
                return true;
            }
        }
        
        return false;
    }
};