// Last updated: 30/07/2026, 10:21:36
class Solution {
public:
    string clearDigits(string s) {
        string ans;
        for(char c:s)
        if(isdigit(c)) ans.pop_back();
        else ans+=c;
        return ans;
    }
};