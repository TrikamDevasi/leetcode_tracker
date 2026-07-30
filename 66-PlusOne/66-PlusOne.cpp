// Last updated: 30/07/2026, 10:24:42
class Solution {
public:
    vector<int> plusOne(vector<int>& d) {
       for(int i=d.size()-1;i>=0;i--)
       if(++d[i]<10)return d;
       else d[i]=0;
       d.insert(d.begin(),1);
       return d;
    }
};