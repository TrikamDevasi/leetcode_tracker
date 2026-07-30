// Last updated: 30/07/2026, 14:21:42
1class Solution {
2public:
3    int compress(vector<char>& chars) {
4        int write = 0, i = 0, n = chars.size();
5        
6        while (i < n) {
7            int start = i;
8            while (i < n && chars[i] == chars[start]) i++;
9            
10            chars[write++] = chars[start];
11            
12            if (i - start > 1) {
13                for (char c : to_string(i - start)) {
14                    chars[write++] = c;
15                }
16            }
17        }
18        
19        return write;
20    }
21};