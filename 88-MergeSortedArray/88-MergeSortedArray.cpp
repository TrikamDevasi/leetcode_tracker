// Last updated: 30/07/2026, 10:24:30
class Solution {
public:
    void merge(vector<int>& a, int m, vector<int>& b, int n) {
        int i = m + n;
        while (n > 0)
            a[--i] = (m > 0 && a[m - 1] > b[n - 1]) ? a[--m] : b[--n];
    }
};