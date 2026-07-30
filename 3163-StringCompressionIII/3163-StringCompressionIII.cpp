// Last updated: 30/07/2026, 14:20:57
1class Solution {
2public:
3    string compressedString(string word) {
4        string res = ""; 
5        int count = 1; 
6        
7        for(int i = 0; i < word.length(); i++){ 
8            if(i + 1 < word.length() && word[i] == word[i + 1]){ 
9                count++; 
10            } else { 
11                while (count > 9) {
12                    res += to_string(9);
13                    res += word[i];
14                    count -= 9;
15                }
16                res += to_string(count); 
17                res += word[i]; 
18                count = 1; 
19            } 
20        } 
21        
22        return res;
23    }
24};