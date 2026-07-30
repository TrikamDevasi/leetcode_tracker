// Last updated: 30/07/2026, 10:25:25
class Solution {
public:
    bool isPalindrome(int x) {
        string s=to_string(x);
        return x>=0&&s==string(s.rbegin(),s.rend());
    }
};