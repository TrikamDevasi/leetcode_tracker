// Last updated: 30/07/2026, 10:22:09
class Solution {
public:
    bool squareIsWhite(string coordinates) {
        return (coordinates[0] - 'a' + coordinates[1] - '1') % 2 != 0;
    }
};