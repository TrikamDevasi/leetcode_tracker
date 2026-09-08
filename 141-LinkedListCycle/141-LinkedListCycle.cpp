// Last updated: 08/09/2026, 10:25:21
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
11    bool hasCycle(ListNode *head, ListNode *dummy = new ListNode(0)) {
12        return head ? (head == dummy ? true : hasCycle(exchange(head->next, dummy), dummy)) : false;
13    }
14};