// Last updated: 30/07/2026, 10:21:38
class Solution {
public:
    string processStr(string s) {
        string result = "";
        for (char c : s) {
            if (islower(c)) {
                // Append lowercase letter
                result.push_back(c);
            } else if (c == '*') {
                // Remove last character if exists
                if (!result.empty()) result.pop_back();
            } else if (c == '#') {
                // Duplicate the string
                result += result;
            } else if (c == '%') {
                // Reverse the string
                reverse(result.begin(), result.end());
            }
        }
        return result;
    }
};
