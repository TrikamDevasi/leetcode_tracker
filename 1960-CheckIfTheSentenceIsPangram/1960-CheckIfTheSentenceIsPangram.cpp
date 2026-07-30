// Last updated: 30/07/2026, 10:22:07
class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_set<char> st;
        for(int i:sentence){
            st.insert(i);
        }
        return st.size()==26;
    }
};