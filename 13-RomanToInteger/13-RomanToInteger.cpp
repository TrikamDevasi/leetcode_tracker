// Last updated: 30/07/2026, 10:25:18
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> values = {
        {'I', 1}, {'V', 5}, {'X', 10},
        {'L', 50}, {'C', 100},
        {'D', 500}, {'M', 1000}
    };
    
    int total = 0;
    for (int i = 0; i < s.size(); i++) {
        // If current value < next value, subtract it
        if (i + 1 < s.size() && values[s[i]] < values[s[i + 1]]) {
            total -= values[s[i]];
        } else {
            total += values[s[i]];
        }
    }
    return total;
    }
};