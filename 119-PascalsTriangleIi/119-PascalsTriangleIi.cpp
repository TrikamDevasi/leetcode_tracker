// Last updated: 30/07/2026, 10:24:15
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // Initialize a vector of size (rowIndex + 1) with 1s
        vector<int> row(rowIndex + 1, 1);

        for (int i = 2; i <= rowIndex; ++i) {
            // Traverse backwards to prevent overwriting values we still need
            for (int j = i - 1; j > 0; --j) {
                row[j] = row[j] + row[j - 1];
            }
        }

        return row;
    }
};