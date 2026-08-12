// Last updated: 12/08/2026, 14:24:20
1class Solution {
2public:
3    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
4        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
5            return a[0] < b[0];
6        });
7
8        int maxWidth = 0;
9
10        for (size_t i = 1; i < points.size(); ++i) {
11            maxWidth = max(maxWidth, points[i][0] - points[i - 1][0]);
12        }
13
14        return maxWidth;
15    }
16};