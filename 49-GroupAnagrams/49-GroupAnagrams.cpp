// Last updated: 30/07/2026, 10:24:47
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        for (string s : strs) {
            string key = s;
            sort(key.begin(), key.end()); 
            groups[key].push_back(s);
        } 
        vector<vector<string>> result;
        for (auto const& [key, group] : groups) {
            result.push_back(group);
        }
        
        return result;
    }
};