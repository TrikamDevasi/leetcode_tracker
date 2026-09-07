// Last updated: 07/09/2026, 10:09:29
1/**
2 * Definition for singly-linked list.
3 * struct ListNode {
4 *     int val;
5 *     ListNode *next;
6 *     ListNode(int x) : val(x), next(NULL) {}
7 * };
8 */
9class Solution {
10public:
11    void deleteNode(ListNode* node) {
12        node->val = node->next->val;
13
14        ListNode* temp = node->next;
15
16        node->next = node->next->next;
17
18        delete temp;
19    }
20};