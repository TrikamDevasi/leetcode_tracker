// Last updated: 10/08/2026, 13:25:26
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
14        ListNode* temp=nullptr;
15        ListNode* curr=head;
16        ListNode* next=nullptr;
17        while(curr>temp){
18            next=curr->next;
19            curr->next=temp;
20            temp=curr;
21            curr=next;
22        }
23        return temp;
24    }
25};