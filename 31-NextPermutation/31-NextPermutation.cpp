// Last updated: 01/08/2026, 21:36:47
1class Solution {
2public:
3    void nextPermutation(vector<int>& nums) {
4        int n = nums.size();
5        int i = n - 2;
6
7        // Step 1: Find the first decreasing element from the right
8        while (i >= 0 && nums[i] >= nums[i + 1]) {
9            i--;
10        }
11
12        // Step 2: If breakpoint found, find the element just larger than nums[i] and swap
13        if (i >= 0) {
14            int j = n - 1;
15            while (nums[j] <= nums[i]) {
16                j--;
17            }
18            swap(nums[i], nums[j]);
19        }
20
21        // Step 3: Reverse the sequence from i + 1 to the end
22        reverse(nums.begin() + i + 1, nums.end());
23    }
24};