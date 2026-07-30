// Last updated: 30/07/2026, 10:24:17
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;

        for (int i = 0; i < numRows; ++i) {
            // Create a row of size (i + 1) initialized with 1s
            vector<int> row(i + 1, 1);

            // Each inner element is the sum of the two elements directly above it
            for (int j = 1; j < i; ++j) {
                row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }

            // Push the completed row into the triangle
            triangle.push_back(row);
        }

        return triangle;
    }
};