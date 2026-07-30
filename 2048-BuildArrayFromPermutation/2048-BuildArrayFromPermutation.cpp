// Last updated: 30/07/2026, 10:22:03
class Solution {
public:
    vector<int> buildArray(vector<int>& a) {
        vector<int> b;
        for(int i:a) b.push_back(a[i]);
        return b;
    }
};