// Last updated: 10/08/2026, 13:11:01
1class Solution {
2public:
3    bool winnerSquareGame(int n) {
4        vector<bool> dp(n + 1, false);
5        
6        for (int i = 1; i <= n; ++i) {
7            for (int k = 1; k * k <= i; ++k) {
8                if (!dp[i - k * k]) {
9                    dp[i] = true;
10                    break; 
11                }
12            }
13        }
14        
15        return dp[n];
16    }
17};