// Last updated: 30/07/2026, 10:22:20
class Solution {
public:
    inline bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    int maxVowels(string s, int k) {
        int current_vowels = 0;
        
        for (int i = 0; i < k; ++i) {
            if (isVowel(s[i])) {
                current_vowels++;
            }
        }
        
        int max_vowels = current_vowels;
        if (max_vowels == k) return k;

        for (int i = k; i < s.length(); ++i) {
            if (isVowel(s[i])) {
                current_vowels++;
            }
            if (isVowel(s[i - k])) {
                current_vowels--;
            }
            
            max_vowels = max(max_vowels, current_vowels);
            if (max_vowels == k) return k;
        }
        
        return max_vowels;
    }
};