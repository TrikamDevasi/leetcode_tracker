// Last updated: 30/07/2026, 10:24:14
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn = prices[0], ans = 0;
        for (int p : prices) {
            mn = min(mn, p);
            ans = max(ans, p - mn);
        }
        return ans;
    }
};