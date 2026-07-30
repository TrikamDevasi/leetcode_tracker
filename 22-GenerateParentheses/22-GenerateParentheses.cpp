// Last updated: 30/07/2026, 10:25:07
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current = "";
        backtrack(result, current, 0, 0, n);
        return result;
    }

private:
    void backtrack(vector<string>& result, string& current, int open, int close, int max_pairs) {
        // Base case: If the current string reaches the maximum required length, it's a valid combination
        if (current.length() == max_pairs * 2) {
            result.push_back(current);
            return;
        }

        // If we can still add an opening parenthesis, do so
        if (open < max_pairs) {
            current.push_back('(');
            backtrack(result, current, open + 1, close, max_pairs);
            current.pop_back(); // Backtrack
        }

        // If we can add a closing parenthesis without violating the rule, do so
        if (close < open) {
            current.push_back(')');
            backtrack(result, current, open, close + 1, max_pairs);
            current.pop_back(); // Backtrack
        }
    }
};