// Last updated: 30/07/2026, 10:21:48
class Solution {
public:
    int countAsterisks(string s) {
        int ans =0,bars =0;
        for(char c:s)
        c=='|'?bars++:ans+=(c=='*'&&bars%2==0);
        return ans;
    }
};