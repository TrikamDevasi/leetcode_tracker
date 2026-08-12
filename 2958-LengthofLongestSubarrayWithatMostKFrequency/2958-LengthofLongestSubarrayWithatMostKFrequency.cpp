// Last updated: 12/08/2026, 13:24:14
1#include <vector>
2#include <unordered_map>
3#include <algorithm>
4
5class Solution {
6public:
7    int maxSubarrayLength(std::vector<int>& nums, int k) {
8        std::unordered_map<int, int> count;
9        int left = 0, max_len = 0;
10        
11        for (int right = 0; right < nums.size(); ++right) {
12            count[nums[right]]++;
13            
14            while (count[nums[right]] > k) {
15                count[nums[left]]--;
16                left++;
17            }
18            
19            max_len = std::max(max_len, right - left + 1);
20        }
21        
22        return max_len;
23    }
24};