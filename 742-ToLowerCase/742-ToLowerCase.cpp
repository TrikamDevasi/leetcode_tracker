// Last updated: 30/07/2026, 10:22:54
class Solution {
public:
    string toLowerCase(string s) {
        for(char &c:s)c=tolower(c);
        return s;
    }
};