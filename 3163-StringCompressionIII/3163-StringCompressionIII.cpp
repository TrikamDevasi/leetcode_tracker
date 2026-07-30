// Last updated: 30/07/2026, 14:09:43
1class Solution {
2public:
3    string compressedString(string word) {
4        string comp = "";
5        int i = 0;
6        int n = word.length();
7        
8        while (i < n) {
9            char c = word[i];
10            int count = 0;
11            
12            // Count matching characters up to at most 9
13            while (i < n && word[i] == c && count < 9) {
14                count++;
15                i++;
16            }
17            
18            // Append format: [count][character]
19            comp += to_string(count) + c;
20        }
21        
22        return comp;
23    }
24};