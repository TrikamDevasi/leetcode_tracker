// Last updated: 01/08/2026, 21:54:54
1class Solution {
2public:
3    int jump(vector<int>& nums) {
4        int jumps = 0;
5        int currentEnd = 0;
6        int farthest = 0;
7
8        for (int i = 0; i < nums.size() - 1; i++) {
9            farthest = max(farthest, i + nums[i]);
10
11            if (i == currentEnd) {
12                jumps++;
13                currentEnd = farthest;
14            }
15        }
16
17        return jumps;
18    }
19};