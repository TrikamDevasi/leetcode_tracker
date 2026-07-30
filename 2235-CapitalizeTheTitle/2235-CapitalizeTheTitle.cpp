// Last updated: 30/07/2026, 10:21:58
#include <string>
#include <sstream>
#include <cctype>

class Solution {
public:
    std::string capitalizeTitle(std::string title) {
        std::stringstream ss(title);
        std::string word;
        std::string result = "";
        
        while (ss >> word) {
            if (!result.empty()) {
                result += " ";
            }
            
            if (word.length() <= 2) {
                for (char &c : word) {
                    c = std::tolower(c);
                }
            } else {
                word[0] = std::toupper(word[0]);
                for (size_t i = 1; i < word.length(); ++i) {
                    word[i] = std::tolower(word[i]);
                }
            }
            result += word;
        }
        
        return result;
    }
};