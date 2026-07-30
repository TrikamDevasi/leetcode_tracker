// Last updated: 30/07/2026, 10:24:01
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;
        
        int min_val = nums[0];
        int max_val = nums[0];
        for (int num : nums) {
            min_val = min(min_val, num);
            max_val = max(max_val, num);
        }
        
        if (min_val == max_val) return 0;
        
        int bucket_size = max(1, (max_val - min_val) / (n - 1));
        int bucket_count = (max_val - min_val) / bucket_size + 1;
        
        vector<int> bucket_min(bucket_count, INT_MAX);
        vector<int> bucket_max(bucket_count, INT_MIN);
        
        for (int num : nums) {
            int idx = (num - min_val) / bucket_size;
            bucket_min[idx] = min(bucket_min[idx], num);
            bucket_max[idx] = max(bucket_max[idx], num);
        }
        
        int max_gap = 0;
        int previous_max = min_val;
        
        for (int i = 0; i < bucket_count; ++i) {
            if (bucket_min[i] == INT_MAX) continue;
            
            max_gap = max(max_gap, bucket_min[i] - previous_max);
            previous_max = bucket_max[i];
        }
        
        return max_gap;
    }
};