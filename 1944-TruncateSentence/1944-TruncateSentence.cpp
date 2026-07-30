// Last updated: 30/07/2026, 10:22:08
class Solution {
public:
    string truncateSentence(string s, int k) {
        int countspaces=0;
        for(int i=0;i<s.length();i++){
            if(s[i]==' '){
                countspaces++;
            }

            if(countspaces==k){
                return s.substr(0,i);
            }
            
    }
    return s;
        }
};