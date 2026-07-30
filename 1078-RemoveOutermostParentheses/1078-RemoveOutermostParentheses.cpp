// Last updated: 30/07/2026, 10:22:39
class Solution {
public:
    string removeOuterParentheses(string s) {
        string result;
        int balance = 0;
        
        for (char c : s) {
            if (c == '(') {
                if (balance > 0) result += c;
                balance++;
            } else {
                balance--;
                if (balance > 0) result += c; 
            }
        }
        return result;
    }
};
