// Last updated: 08/09/2026, 09:57:41
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
13    ListNode* reverseList(ListNode* head) {
14        ListNode* prev = nullptr;
15        ListNode* curr = head;
16        
17        while (curr != nullptr) {
18            ListNode* nextTemp = curr->next;
19            curr->next = prev;              
20            prev = curr;                     
21            curr = nextTemp;             
22        }
23        
24        return prev; 
25    }
26};