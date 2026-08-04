// Last updated: 04/08/2026, 11:52:34
1class Solution {
2public:
3    vector<int> findMissingElements(vector<int>& nums) {
4        // Find the minimum and maximum values in nums
5        int min_val = *min_element(nums.begin(), nums.end());
6        int max_val = *max_element(nums.begin(), nums.end());
7        
8        // Put all elements in a hash set for O(1) lookup
9        unordered_set<int> present(nums.begin(), nums.end());
10        vector<int> missing;
11        
12        // Iterate through the full range [min_val, max_val]
13        for (int i = min_val; i <= max_val; ++i) {
14            if (present.find(i) == present.end()) {
15                missing.push_back(i);
16            }
17        }
18        
19        return missing;
20    }
21};