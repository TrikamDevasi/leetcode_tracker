// Last updated: 05/08/2026, 14:31:14
1class Solution {
2public:
3    bool isPalindrome(ListNode* head) {
4        if (!head || !head->next) return true;
5
6        // 1. Find the middle of the linked list
7        ListNode* slow = head;
8        ListNode* fast = head;
9        while (fast && fast->next) {
10            slow = slow->next;
11            fast = fast->next->next;
12        }
13
14        // 2. Reverse the second half of the list starting from 'slow'
15        ListNode* prev = nullptr;
16        ListNode* curr = slow;
17        while (curr) {
18            ListNode* nextNode = curr->next;
19            curr->next = prev;
20            prev = curr;
21            curr = nextNode;
22        }
23
24        // 3. Compare the first half and the reversed second half
25        ListNode* first = head;
26        ListNode* second = prev; // 'prev' is now the head of the reversed second half
27        while (second) {
28            if (first->val != second->val) {
29                return false;
30            }
31            first = first->next;
32            second = second->next;
33        }
34
35        return true;
36    }
37};