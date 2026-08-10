// Last updated: 10/08/2026, 14:16:06
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
13    ListNode* partition(ListNode* head, int x) {
14        ListNode less_head(0);
15        ListNode greater_head(0);
16        
17        ListNode* less = &less_head;
18        ListNode* greater = &greater_head;
19        
20        while (head != nullptr) {
21            if (head->val < x) {
22                less->next = head;
23                less = less->next;
24            } else {
25                greater->next = head;
26                greater = greater->next;
27            }
28            head = head->next;
29        }
30        
31        // Terminate the list to prevent cycles
32        greater->next = nullptr;
33        // Connect the less list with the greater list
34        less->next = greater_head.next;
35        
36        return less_head.next;
37    }
38};