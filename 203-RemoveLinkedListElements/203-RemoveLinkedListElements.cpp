// Last updated: 30/07/2026, 10:23:41
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // Create a dummy node that points to the head
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* curr = dummy;
        
        while (curr->next != nullptr) {
            if (curr->next->val == val) {
                // Node to be deleted
                ListNode* temp = curr->next;
                curr->next = curr->next->next; // Skip the node
                delete temp;                   // Free memory
            } else {
                // Only advance curr if we didn't delete a node
                curr = curr->next;
            }
        }
        
        ListNode* newHead = dummy->next;
        delete dummy; // Clean up the dummy node memory
        return newHead;
    }
};