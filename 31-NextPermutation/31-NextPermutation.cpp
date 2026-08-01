// Last updated: 01/08/2026, 21:48:06
1class Solution {
2public:
3    string multiply(string num1, string num2) {
4        if (num1 == "0" || num2 == "0")
5            return "0";
6
7        int n = num1.size(), m = num2.size();
8        vector<int> result(n + m, 0);
9
10        for (int i = n - 1; i >= 0; i--) {
11            for (int j = m - 1; j >= 0; j--) {
12                int mul = (num1[i] - '0') * (num2[j] - '0');
13                int sum = mul + result[i + j + 1];
14
15                result[i + j + 1] = sum % 10;
16                result[i + j] += sum / 10;
17            }
18        }
19
20        string ans = "";
21        for (int num : result) {
22            if (!(ans.empty() && num == 0))
23                ans += (num + '0');
24        }
25
26        return ans.empty() ? "0" : ans;
27    }
28};