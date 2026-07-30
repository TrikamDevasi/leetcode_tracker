// Last updated: 30/07/2026, 10:22:36
class Solution {
public:
    string removeDuplicates(string s) {
        string res="";
        for(char ch:s){
            if(!res.empty()&&res.back()==ch){
                res.pop_back();
            }
            else{
                res.push_back(ch);
            }
        }
        return res;
    }
};