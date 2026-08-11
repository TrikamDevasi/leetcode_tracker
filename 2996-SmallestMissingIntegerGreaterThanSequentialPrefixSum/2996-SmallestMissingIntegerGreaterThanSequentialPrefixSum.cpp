// Last updated: 11/08/2026, 11:40:03
1class Solution {
2public:
3    int missingInteger(vector<int>& nums) {
4        int i = 0;
5        while (i + 1 < nums.size() && nums[i + 1] == nums[i] + 1) {
6            i++;
7        }
8        
9        int prefixSum = 0;
10        for (int j = 0; j <= i; j++) {
11            prefixSum += nums[j];
12        }
13
14        unordered_set<int> s(nums.begin(), nums.end());
15        int x = prefixSum;
16        while (s.count(x)) {
17            x++;
18        }
19        
20        return x;
21    }
22};