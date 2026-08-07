// Last updated: 07/08/2026, 14:04:45
1class Solution {
2public:
3    ListNode* reverseBetween(ListNode* head, int left, int right) {
4        if (!head || left == right) return head;
5
6        // Dummy node to simplify edge cases (like reversing from head)
7        ListNode* dummy = new ListNode(0);
8        dummy->next = head;
9        ListNode* prev = dummy;
10
11        // Step 1: Move `prev` to the node just before `left`
12        for (int i = 1; i < left; i++) {
13            prev = prev->next;
14        }
15
16        // Step 2: Reverse the sublist from `left` to `right`
17        ListNode* curr = prev->next;
18        ListNode* next = nullptr;
19        ListNode* sublistPrev = nullptr;
20
21        for (int i = left; i <= right; i++) {
22            next = curr->next;
23            curr->next = sublistPrev;
24            sublistPrev = curr;
25            curr = next;
26        }
27
28        // Step 3: Connect the reversed sublist back
29        prev->next->next = curr;   // Tail of reversed part connects to `curr`
30        prev->next = sublistPrev;  // `prev` connects to new head of reversed part
31
32        return dummy->next;
33    }
34};
35