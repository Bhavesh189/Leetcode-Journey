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
13    ListNode* oddEvenList(ListNode* head) {
14        if(!head) return NULL; 
15        ListNode *e = new ListNode(-1), *o = new ListNode(-1), *a1 = e, *a2 = o;
16        int len = 0;
17
18        while(head) {
19            len++;
20            ListNode* next = head->next;
21            head->next = NULL; 
22            if(len&1) {
23                o->next = head;
24                o = o->next;
25            } else {
26                e->next = head;
27                e = e->next;
28            }
29
30            head = next;
31        }
32
33        a1 = a1->next;
34        a2 = a2->next;
35
36        o->next = a1;
37
38        return a2;
39    }
40};