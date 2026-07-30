// Last updated: 30/07/2026, 13:42:00
1class Solution {
2public:
3    int compress(vector<char>& chars) {
4        int write = 0;
5        int count = 0;
6        
7        for (int i = 0; i < chars.size(); i++) {
8            count++;
9            
10            // Check if we reached the end of a group (last character or next char is different)
11            if (i + 1 == chars.size() || chars[i] != chars[i + 1]) {
12                chars[write++] = chars[i]; // Write the character
13                
14                if (count > 1) {
15                    string countStr = to_string(count);
16                    for (char c : countStr) {
17                        chars[write++] = c; // Write each digit of the count
18                    }
19                }
20                
21                count = 0; // Reset count for the next group
22            }
23        }
24        
25        return write; // Return the new length
26    }
27};