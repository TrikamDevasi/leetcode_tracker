// Last updated: 10/08/2026, 14:15:58
1class Solution {
2public:
3    int maxProduct(vector<string>& words) {
4        int n = words.size();
5        vector<int> masks(n, 0);
6        
7        // Compute bitmask for each word
8        for (int i = 0; i < n; ++i) {
9            for (char c : words[i]) {
10                masks[i] |= (1 << (c - 'a'));
11            }
12        }
13        
14        int max_prod = 0;
15        
16        // Compare pairs of words
17        for (int i = 0; i < n; ++i) {
18            for (int j = i + 1; j < n; ++j) {
19                // If bitwise AND is 0, the two words share no common letters
20                if ((masks[i] & masks[j]) == 0) {
21                    int prod = words[i].length() * words[j].length();
22                    max_prod = max(max_prod, prod);
23                }
24            }
25        }
26        
27        return max_prod;
28    }
29};