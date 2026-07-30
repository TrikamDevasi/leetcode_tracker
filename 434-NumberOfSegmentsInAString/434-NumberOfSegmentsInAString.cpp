// Last updated: 30/07/2026, 10:23:09
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSegments(string s) {
        int segmentCount = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ' && (i == 0 || s[i-1] == ' ')) {
                segmentCount++;
            }
        }
        return segmentCount;
    }
};
