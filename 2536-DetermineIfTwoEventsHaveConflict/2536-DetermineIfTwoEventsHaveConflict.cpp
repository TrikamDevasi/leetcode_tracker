// Last updated: 30/07/2026, 10:21:43
class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        return event1[0] <= event2[1] && event2[0] <= event1[1];
    }
};