// Last updated: 11/08/2026, 14:04:21
1/**
2 * Definition for singly-linked list.
3 * struct ListNode {
4 *     int val;
5 *     ListNode *next;
6 *     ListNode() : val(0), next(nullptr) {}
7 *     ListNode(int x) : val(x), next(nullptr) {}
8 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
9 * };
10 */
11class Solution {
12public:
13    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
14        unordered_set<int> numSet(nums.begin(), nums.end());
15        
16        ListNode dummy(0, head);
17        ListNode* curr = &dummy;
18        
19        while (curr->next != nullptr) {
20            if (numSet.count(curr->next->val)) {
21                curr->next = curr->next->next;
22            } else {
23                curr = curr->next;
24            }
25        }
26        
27        return dummy.next;
28    }
29};