// Last updated: 07/09/2026, 09:20:31
1class Solution {
2public:
3    int numDistinct(string s, string t) {
4        int n = t.size();
5        vector<unsigned long long> dp(n + 1);
6        dp[0] = 1;
7
8        for (char c : s) {
9            for (int j = n - 1; j >= 0; j--) {
10                if (c == t[j])
11                    dp[j + 1] += dp[j];
12            }
13        }
14
15        return dp[n];
16    }
17};