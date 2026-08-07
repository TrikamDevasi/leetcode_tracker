// Last updated: 07/08/2026, 14:06:18
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
13    ListNode* rotateRight(ListNode* head, int k) {
14        if (!head || !head->next || k == 0) return head;
15
16        // Step 1: Find the length and tail node
17        ListNode* tail = head;
18        int length = 1;
19        while (tail->next) {
20            tail = tail->next;
21            length++;
22        }
23
24        // Step 2: Form a circular linked list
25        tail->next = head;
26
27        // Step 3: Find the effective rotations needed
28        k = k % length;
29        int stepsToNewTail = length - k;
30
31        // Step 4: Traverse to the new tail
32        ListNode* newTail = tail;
33        while (stepsToNewTail--) {
34            newTail = newTail->next;
35        }
36
37        // Step 5: Set the new head and break the circle
38        ListNode* newHead = newTail->next;
39        newTail->next = nullptr;
40
41        return newHead;
42    }
43};