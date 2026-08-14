// Last updated: 14/08/2026, 16:05:01
1class Solution {
2public:
3    int maximumLengthSubstring(string s) {
4        unordered_map<char, int> count;
5        int max_len = 0;
6        int left = 0;
7
8        for (int right = 0; right < s.length(); ++right) {
9            count[s[right]]++;
10            
11            while (count[s[right]] > 2) {
12                count[s[left]]--;
13                left++;
14            }
15            
16            max_len = max(max_len, right - left + 1);
17        }
18
19        return max_len;
20    }
21};