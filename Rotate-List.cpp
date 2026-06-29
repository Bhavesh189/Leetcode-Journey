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
13    ListNode* rotateRight(ListNode* head, int k) {
14        if(!head || !head->next) return head;
15        if(k == 0) return head;
16        int l = 0;
17        ListNode* curr = head;
18
19        while(curr->next) {
20            curr = curr->next;
21            l++;
22        }
23
24        l++;
25        k=k%l;
26
27        curr->next = head;
28        int a = abs(l-k);
29
30        int c = 0;
31
32        ListNode* prev = NULL;
33
34        while( c != a ) {
35            prev = head;
36            head = head->next;
37            c++;
38        }
39
40        prev->next = NULL;
41
42        return head;
43    }
44};