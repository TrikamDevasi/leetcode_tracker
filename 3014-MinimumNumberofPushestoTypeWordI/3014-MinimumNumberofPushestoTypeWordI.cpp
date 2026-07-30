// Last updated: 30/07/2026, 14:49:46
1class Solution {
2public:
3    int minimumPushes(string word) {
4        int n = word.length();
5        int ans = 0;
6        
7        for (int i = 0; i < n; i++) {
8            ans += (i / 8) + 1;
9        }
10        
11        return ans;
12    }
13};