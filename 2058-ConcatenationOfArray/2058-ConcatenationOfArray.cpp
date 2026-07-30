// Last updated: 30/07/2026, 10:22:11
class Solution {
public:
    vector<int> getConcatenation(vector<int>& a) {
        a.insert(a.end(),a.begin(),a.end());
        return a;
    }
};