// Last updated: 30/07/2026, 10:22:06
class Solution {
public:
    int sumBase(int n, int k) {
        int s=0;
        while(n)s+= n%k,n/=k;
        return s;
    }
};