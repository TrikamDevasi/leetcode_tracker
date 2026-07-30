// Last updated: 30/07/2026, 14:20:31
1class Solution {
2public:
3    string compressedString(string word) {string res = ""; int count = 1;  for(int i = 0; i < word.length(); i++){ if(i + 1 < word.length() && word[i] == word[i + 1]){count++;} else {while (count > 9) {
4 res += to_string(9);
5                    res += word[i];
6                    count -= 9;
7                }
8                res += to_string(count); 
9                res += word[i]; 
10                count = 1; 
11            } 
12        } 
13        
14        return res;
15    }
16};