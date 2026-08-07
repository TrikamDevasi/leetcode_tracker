// Last updated: 07/08/2026, 13:47:51
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
13    ListNode* deleteDuplicates(ListNode* head) {
14        ListNode* current = head;
15
16        while (current != nullptr && current->next != nullptr) {
17            if (current->val == current->next->val) {
18                ListNode* temp = current->next;
19                current->next = current->next->next;
20              
21            } else {
22                current = current->next;
23            }
24        }
25
26        return head;
27    }
28};