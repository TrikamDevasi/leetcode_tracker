// Last updated: 30/07/2026, 10:22:12
class Solution {
public:
    bool halvesAreAlike(string s) {
        string vowels = "aeiouAEIOU";
        int count = 0,n=s.size();
        for(int i = 0;i<n/2;i++){
            if(vowels.find(s[i])!= string::npos)count++;
        }
        for(int i=n/2;i<n;i++){
            if(vowels.find(s[i])!=string::npos)count--;
        }return count ==0;
       
    }
};