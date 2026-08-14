// Last updated: 14/08/2026, 12:02:12
1class Solution {
2public:
3    int minimumPairRemoval(std::vector<int>& nums) {
4        int operations = 0;
5 
6        while (!isSorted(nums)) {
7            int minSum = INT_MAX;
8            int minIdx = 0;
9
10            for (int i = 0; i < (int)nums.size() - 1; i++) {
11                int sum = nums[i] + nums[i + 1];
12                if (sum < minSum) {
13                    minSum = sum;
14                    minIdx = i;
15                }
16            }
17
18            nums[minIdx] = minSum;
19            nums.erase(nums.begin() + minIdx + 1);
20            
21            operations++;
22        }
23        
24        return operations;
25    }
26
27private:
28    bool isSorted(const std::vector<int>& nums) {
29        for (size_t i = 0; i + 1 < nums.size(); i++) {
30            if (nums[i] > nums[i + 1]) {
31                return false;
32            }
33        }
34        return true;
35    }
36};