// Last updated: 30/07/2026, 10:23:58
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans;

        while (columnNumber > 0) {
            columnNumber--;
            ans += char('A' + columnNumber % 26);
            columnNumber /= 26;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};