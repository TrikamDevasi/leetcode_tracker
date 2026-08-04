// Last updated: 04/08/2026, 14:20:32
1class MyLinkedList {
2private:
3    struct Node {
4        int val;
5        Node* next;
6        Node(int v) : val(v), next(nullptr) {}
7    };
8
9    Node* head;
10    int size;
11
12public:
13    MyLinkedList() {
14        head = nullptr;
15        size = 0;
16    }
17    
18    int get(int index) {
19        if (index < 0 || index >= size) return -1;
20        
21        Node* curr = head;
22        for (int i = 0; i < index; ++i) {
23            curr = curr->next;
24        }
25        return curr->val;
26    }
27    
28    void addAtHead(int val) {
29        Node* newNode = new Node(val);
30        newNode->next = head;
31        head = newNode;
32        size++;
33    }
34    
35    void addAtTail(int val) {
36        if (size == 0) {
37            addAtHead(val);
38            return;
39        }
40        Node* newNode = new Node(val);
41        Node* curr = head;
42        while (curr->next != nullptr) {
43            curr = curr->next;
44        }
45        curr->next = newNode;
46        size++;
47    }
48    
49    void addAtIndex(int index, int val) {
50        if (index > size) return; // Index greater than length: not inserted
51        if (index <= 0) {         // Index <= 0: insert at head
52            addAtHead(val);
53            return;
54        }
55        if (index == size) {      // Index equals length: insert at tail
56            addAtTail(val);
57            return;
58        }
59
60        Node* newNode = new Node(val);
61        Node* curr = head;
62        for (int i = 0; i < index - 1; ++i) {
63            curr = curr->next;
64        }
65        newNode->next = curr->next;
66        curr->next = newNode;
67        size++;
68    }
69    
70    void deleteAtIndex(int index) {
71        if (index < 0 || index >= size) return;
72
73        if (index == 0) {
74            Node* temp = head;
75            head = head->next;
76            delete temp;
77        } else {
78            Node* curr = head;
79            for (int i = 0; i < index - 1; ++i) {
80                curr = curr->next;
81            }
82            Node* temp = curr->next;
83            curr->next = temp->next;
84            delete temp;
85        }
86        size--;
87    }
88};