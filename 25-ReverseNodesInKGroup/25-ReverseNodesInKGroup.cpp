// Last updated: 30/07/2026, 10:25:03
/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode() : val(0), next(nullptr) {}
 * ListNode(int x) : val(x), next(nullptr) {}
 * ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || k == 1) return head;
        
        ListNode dummy(0);
        dummy.next = head;
        
        ListNode* groupPrev = &dummy;
        
        while (true) {
            // Check if there are at least k nodes left in the list
            ListNode* kth = getKthNode(groupPrev, k);
            if (kth == nullptr) {
                break; // Less than k nodes left, leave them as they are
            }
            
            // Store the node right after the kth node to reconnect later
            ListNode* groupNext = kth->next;
            
            // Reverse the current k-group segment
            ListNode* prev = groupNext; // Connect the tail of reversed group directly to groupNext
            ListNode* curr = groupPrev->next;
            
            while (curr != groupNext) {
                ListNode* tmp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = tmp;
            }
            
            // Adjust the group boundary pointers
            ListNode* tmp = groupPrev->next; // The old head becomes the new tail of the reversed group
            groupPrev->next = kth;           // The old kth node becomes the new head of the group
            groupPrev = tmp;                 // Move groupPrev forward for the next iteration
        }
        
        return dummy.next;
    }

private:
    // Helper function to find the kth node from the current position
    ListNode* getKthNode(ListNode* curr, int k) {
        while (curr != nullptr && k > 0) {
            curr = curr->next;
            k--;
        }
        return curr;
    }
};