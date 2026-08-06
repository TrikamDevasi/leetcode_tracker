// Last updated: 06/08/2026, 14:31:37
1class Solution {
2public:
3    string countAndSay(int n) {
4        string current = "1";
5        
6        for (int i = 1; i < n; ++i) {
7            string next_str = "";
8            int count = 1;
9            
10            for (int j = 0; j < current.length(); ++j) {
11                // If adjacent characters are equal, increment count
12                if (j + 1 < current.length() && current[j] == current[j + 1]) {
13                    count++;
14                } else {
15                    // Append frequency followed by the character
16                    next_str += to_string(count) + current[j];
17                    count = 1; // Reset count for the next run
18                }
19            }
20            current = next_str;
21        }
22        
23        return current;
24    }
25};