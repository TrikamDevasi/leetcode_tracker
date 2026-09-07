// Last updated: 07/09/2026, 09:21:01
1class Solution {
2public:
3    int distinctSubseqII(string s) {
4        const int MOD = 1e9 + 7;
5        vector<long long> dp(26, 0);
6
7        long long total = 0;
8
9        for (char c : s) {
10            int x = c - 'a';
11            long long add = (total + 1) % MOD;
12
13            total = (total + add - dp[x] + MOD) % MOD;
14            dp[x] = add;
15        }
16
17        return total;
18    }
19};