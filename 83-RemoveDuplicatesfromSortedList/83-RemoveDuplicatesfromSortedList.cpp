// Last updated: 04/08/2026, 14:29:58
1class Solution {
2public:
3    ListNode* deleteDuplicates(ListNode* head) {
4        // Base case: if the list is empty, return nullptr immediately
5        if (head == nullptr) return nullptr;
6
7        ListNode* curr = head;
8        while (curr->next != nullptr) {
9            if (curr->val == curr->next->val) {
10                curr->next = curr->next->next;
11            } else {
12                curr = curr->next;
13            }
14        }
15        
16        return head;
17    }
18};