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
14        if(!head) return NULL;
15        if(!head->next) return head;
16
17        ListNode* curr = head;
18        ListNode* next = head->next;
19        ListNode* prev = NULL;
20
21        while(curr) {
22            next = curr->next;
23            curr->next = prev;
24            prev = curr;
25            curr = next;
26        }
27
28        return prev;
29    }
30};