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
13    ListNode* deleteMiddle(ListNode* head) {
14        if(!head || !head->next) return NULL;
15        ListNode* curr = head;
16        ListNode* fast = head;
17        ListNode* prev = NULL;
18
19        while(fast && fast->next) {
20            prev = curr;
21            curr = curr->next;
22            fast = fast->next->next;
23        }
24
25        prev->next = prev->next->next;
26
27        return head;
28    }
29};