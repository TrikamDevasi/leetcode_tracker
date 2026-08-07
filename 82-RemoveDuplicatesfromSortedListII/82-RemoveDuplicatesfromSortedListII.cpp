// Last updated: 07/08/2026, 14:14:39
1class Solution {
2public:
3    ListNode* deleteDuplicates(ListNode* head) {
4        // Dummy node to handle edge cases where head itself needs to be removed
5        ListNode* dummy = new ListNode(0, head);
6        ListNode* prev = dummy;
7        
8        while (head != nullptr) {
9            // Check if current node has duplicates
10            if (head->next != nullptr && head->val == head->next->val) {
11                // Skip all nodes with the same value
12                while (head->next != nullptr && head->val == head->next->val) {
13                    head = head->next;
14                }
15                // Connect prev node to the node after the duplicate sequence
16                prev->next = head->next;
17            } else {
18                // No duplicate for this node, advance prev pointer
19                prev = prev->next;
20            }
21            head = head->next;
22        }
23        
24        ListNode* result = dummy->next;
25        delete dummy; // Clean up allocated dummy node
26        return result;
27    }
28};