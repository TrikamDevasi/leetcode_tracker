// Last updated: 01/08/2026, 21:43:53
1class Solution {
2public:
3    vector<vector<int>> ans;
4    vector<int> temp;
5
6    void solve(int idx, vector<int>& candidates, int target) {
7        if (target == 0) {
8            ans.push_back(temp);
9            return;
10        }
11
12        for (int i = idx; i < candidates.size(); i++) {
13            // Skip duplicates
14            if (i > idx && candidates[i] == candidates[i - 1])
15                continue;
16
17            // No need to continue if current number is larger
18            if (candidates[i] > target)
19                break;
20
21            temp.push_back(candidates[i]);
22            solve(i + 1, candidates, target - candidates[i]); // use next index
23            temp.pop_back();
24        }
25    }
26
27    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
28        sort(candidates.begin(), candidates.end());
29        solve(0, candidates, target);
30        return ans;
31    }
32};