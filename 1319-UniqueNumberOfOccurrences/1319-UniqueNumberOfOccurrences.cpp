// Last updated: 30/07/2026, 10:22:31
class Solution {
public:
    bool uniqueOccurrences(std::vector<int>& arr) {
        std::unordered_map<int, int> counts;
        
        for (int i = 0; i < arr.size(); i++) {
            int number = arr[i];
            counts[number] = counts[number] + 1;
        }
        
        std::unordered_set<int> seenFrequencies;
        
        for (auto pair : counts) {
            int frequency = pair.second;
            
            if (seenFrequencies.count(frequency) > 0) {
                return false;
            }
            
            seenFrequencies.insert(frequency);
        }
        
        return true;
    }
};