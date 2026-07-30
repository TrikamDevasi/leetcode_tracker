// Last updated: 30/07/2026, 10:22:25
class Solution {
public:
    int numberOfSteps(int num) {
        int steps=0;
        while (num>0){
            if(num%2==0){
                num/=2;
            }else{
                num-=1;
            }
            steps++;
        }
        return steps;
    }
};