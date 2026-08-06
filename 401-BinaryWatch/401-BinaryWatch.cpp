// Last updated: 06/08/2026, 14:32:49
1#include <vector>
2#include <string>
3
4class Solution {
5public:
6    vector<string> readBinaryWatch(int turnedOn) {
7        vector<string> result;
8        
9        for (int h = 0; h < 12; ++h) {
10            for (int m = 0; m < 60; ++m) {
11                // Count the number of set bits (LEDs on) for hours and minutes
12                if (__builtin_popcount(h) + __builtin_popcount(m) == turnedOn) {
13                    result.push_back(to_string(h) + (m < 10 ? ":0" : ":") + to_string(m));
14                }
15            }
16        }
17        
18        return result;
19    }
20};