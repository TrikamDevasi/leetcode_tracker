// Last updated: 05/08/2026, 14:32:21
1class Solution {
2public:
3    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
4        if (!headA || !headB) return nullptr;
5
6        ListNode *ptrA = headA;
7        ListNode *ptrB = headB;
8
9        while (ptrA != ptrB) {
10            ptrA = (ptrA == nullptr) ? headB : ptrA->next;
11            ptrB = (ptrB == nullptr) ? headA : ptrB->next; // Corrected to headA
12        }
13
14        return ptrA;
15    }
16};