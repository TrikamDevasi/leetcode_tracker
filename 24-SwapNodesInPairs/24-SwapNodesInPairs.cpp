// Last updated: 30/07/2026, 10:25:04
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
    ListNode* swapPairs(ListNode* head) {
        // If the list is empty or has only one node, no swapping is needed
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        
        // Traverse the list as long as there is a pair to swap
        while (prev->next != nullptr && prev->next->next != nullptr) {
            ListNode* first = prev->next;
            ListNode* second = prev->next->next;
            
            // Adjust pointers to swap the two nodes
            first->next = second->next;
            second->next = first;
            prev->next = second;
            
            // Move the prev pointer two steps forward for the next pair
            prev = first;
        }
        
        return dummy.next;
    }
};