// Last updated: 30/07/2026, 10:22:29
class Solution {
public:
    int balancedStringSplit(string s) {
        int count = 0;
        int balance = 0;
        for( char ch : s){
            if(ch=='L'){
                balance++;
            } else {
                balance--;
            }
            if(balance==0){
                count++;
            }
        }
        return count;
    }
};