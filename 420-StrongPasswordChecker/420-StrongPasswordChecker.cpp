// Last updated: 06/08/2026, 16:15:44
1/**
2 * Definition for singly-linked list.
3 * struct ListNode {
4 * int val;
5 * ListNode *next;
6 * ListNode() : val(0), next(nullptr) {}
7 * ListNode(int x) : val(x), next(nullptr) {}
8 * ListNode(int x, ListNode *next) : val(x), next(next) {}
9 * };
10 */
11class Solution {
12public:
13    ListNode* swapPairs(ListNode* head) {
14        ListNode **pp = &head, *a, *b;
15        while ((a = *pp) && (b = a->next)) {
16            a->next = b->next;
17            b->next = a;
18            *pp = b;
19            pp = &(a->next);
20        }
21        return head;
22    }
23};