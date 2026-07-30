// Last updated: 30/07/2026, 10:21:46
class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> counts;
        int max_freq = 0;
        int ans = -1;
        
        for (int num : nums) {
            if (num % 2 == 0) {
                counts[num]++;
                
                if (counts[num] > max_freq) {
                    max_freq = counts[num];
                    ans = num;
                } else if (counts[num] == max_freq) {
                    ans = min(ans, num);
                }
            }
        }
        
        return ans;
    }
};