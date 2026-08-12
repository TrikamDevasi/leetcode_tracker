// Last updated: 12/08/2026, 14:27:01
1class Solution {
2public:
3    vector<string> findRepeatedDnaSequences(string s) {
4        vector<string> result;
5        if (s.length() < 10) return result;
6
7        unordered_map<string, int> count;
8        for (int i = 0; i <= (int)s.length() - 10; ++i) {
9            string sub = s.substr(i, 10);
10            count[sub]++;
11        }
12        for (const auto& [sub, freq] : count) {
13            if (freq > 1) {
14                result.push_back(sub);
15            }
16        }
17
18        return result;
19    }
20};