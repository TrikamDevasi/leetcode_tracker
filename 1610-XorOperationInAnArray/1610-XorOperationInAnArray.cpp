// Last updated: 30/07/2026, 10:22:17
class Solution {
public:
    int xorOperation(int n, int start) {
        int result=0;
        for(int i=0;i<n;i++){
            result^=(start+2*i);
        }
        return result;
    }
};