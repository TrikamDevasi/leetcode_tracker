// Last updated: 30/07/2026, 10:23:01
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());

        int longest = 0;
        int start = 0;

        for (int end = 0; end < nums.size(); end++) {
            while (nums[end] - nums[start] > 1) {
                start++;
            }
            if (nums[end] - nums[start] == 1) {
                longest = max(longest, end - start + 1);
            }
        }
        return longest;
    }
};
