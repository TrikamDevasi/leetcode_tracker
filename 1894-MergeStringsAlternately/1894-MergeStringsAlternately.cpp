// Last updated: 30/07/2026, 10:22:14
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
         string result;
    int n = word1.size(), m = word2.size();
    int maxLen = max(n, m);

    for (int i = 0; i < maxLen; i++) {
        if (i < n) result.push_back(word1[i]); 
        if (i < m) result.push_back(word2[i]);  
    }
    return result;
    }
};