// Last updated: 12/08/2026, 14:28:28
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
13    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
14        ListNode* start = list1;
15    
16        for (int i = 0; i < a - 1; ++i) {
17            start = start->next;
18        }
19
20        ListNode* end = start;
21        for (int i = 0; i < b - a + 1; ++i) {
22            end = end->next;
23        }
24
25        start->next = list2;
26
27        ListNode* list2Tail = list2;
28        while (list2Tail->next != nullptr) {
29            list2Tail = list2Tail->next;
30        }
31
32        list2Tail->next = end->next;
33
34        end->next = nullptr;
35        
36        return list1;
37    }
38};