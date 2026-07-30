// Last updated: 30/07/2026, 10:21:41
class Solution {
public:
    int maxScore(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        long long prefix_sum = 0;
        int score = 0;
        
        for (int num : nums) {
            prefix_sum += num;
            if (prefix_sum > 0) {
                score++;
            } else {
                break;
            }
        }
        
        return score;
    }
};