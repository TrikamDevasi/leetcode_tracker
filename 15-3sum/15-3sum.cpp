// Last updated: 30/07/2026, 10:25:15
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
        sort(a.begin(), a.end());
        vector<vector<int>> r;
        for (int i = 0, n = a.size(); i < n; i++) {
            if (i && a[i] == a[i - 1]) continue;
            int l = i + 1, h = n - 1;
            while (l < h) {
                int s = a[i] + a[l] + a[h];
                if (s < 0) l++;
                else if (s > 0) h--;
                else {
                    r.push_back({a[i], a[l++], a[h--]});
                    while (l < h && a[l] == a[l - 1]) l++;
                    while (l < h && a[h] == a[h + 1]) h--;
                }
            }
        }
        return r;
    }
};