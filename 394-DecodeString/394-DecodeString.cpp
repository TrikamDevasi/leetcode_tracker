// Last updated: 30/07/2026, 10:23:14
class Solution {
public:

    string solve(string &s, int &i) {

        string result = "";

        while(i < s.size() && s[i] != ']') {

            if(isalpha(s[i])) {
                result += s[i];
                i++;
            }
            else {

                int num = 0;

                while(i < s.size() && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }

                i++; 

                string temp = solve(s, i);

                i++; 

                while(num--) {
                    result += temp;
                }
            }
        }

        return result;
    }

    string decodeString(string s) {

        int i = 0;

        return solve(s, i);
    }
};