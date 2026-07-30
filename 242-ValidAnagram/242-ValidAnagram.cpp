// Last updated: 30/07/2026, 10:23:31
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() !=t.size()) return false;
        int a[26]={};
        for(int i=0;i<s.size();++i) a[s[i]-'a']++,a[t[i]-'a']--;
        for(int x:a) if(x) return false;
        return true;
    }
};