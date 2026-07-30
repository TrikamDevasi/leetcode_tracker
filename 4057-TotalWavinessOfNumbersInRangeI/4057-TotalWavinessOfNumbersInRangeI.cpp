// Last updated: 30/07/2026, 10:21:30
#include <string>
#include <vector>

class Solution {
private:
    int getWaviness(int n) {
        // Any number with fewer than 3 digits has a waviness of 0
        if (n < 100) return 0;
        
        std::string s = std::to_string(n);
        int waviness = 0;
        int len = s.length();
        
        // First and last digits cannot be peaks or valleys
        for (int i = 1; i < len - 1; ++i) {
            if (s[i] > s[i - 1] && s[i] > s[i + 1]) {
                waviness++; // Peak
            } else if (s[i] < s[i - 1] && s[i] < s[i + 1]) {
                waviness++; // Valley
            }
        }
        
        return waviness;
    }

public:
    int totalWaviness(int num1, int num2) {
        int totalSum = 0;
        for (int i = num1; i <= num2; ++i) {
            totalSum += getWaviness(i);
        }
        return totalSum;
    }
};