// Last updated: 30/07/2026, 10:23:08
class Solution {
public:
    std::vector<int> findAnagrams(std::string s, std::string p) {
        int s_len = s.length();
        int p_len = p.length();

        if (s_len < p_len) return {};

        std::vector<int> p_freq(26, 0);
        std::vector<int> window_freq(26, 0);
        std::vector<int> result;

    
        for (int i = 0; i < p_len; i++) {
            p_freq[p[i] - 'a']++;
            window_freq[s[i] - 'a']++;
        }

        if (p_freq == window_freq) {
            result.push_back(0);
        }

        for (int i = p_len; i < s_len; i++) {
            window_freq[s[i] - 'a']++;

            window_freq[s[i - p_len] - 'a']--;

            if (p_freq == window_freq) {
                result.push_back(i - p_len + 1);
            }
        }

        return result;
    }
};