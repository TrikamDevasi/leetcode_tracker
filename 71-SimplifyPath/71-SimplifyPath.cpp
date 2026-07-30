// Last updated: 30/07/2026, 10:24:38
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        stringstream ss(path);
        string token;
        
        while (getline(ss, token, '/')) {
            if (token == "" || token == ".") {
                continue; // skip
            } else if (token == "..") {
                if (!stack.empty()) stack.pop_back(); // go up
            } else {
                stack.push_back(token); // valid directory/file
            }
        }
        
        string result = "/";
        for (int i = 0; i < stack.size(); i++) {
            result += stack[i];
            if (i < stack.size() - 1) result += "/";
        }
        return result;
    }
};
