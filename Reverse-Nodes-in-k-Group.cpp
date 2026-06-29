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
13    ListNode* reverseKGroup(ListNode* head, int k) {
14        if(!head || !head->next) return head;
15        ListNode* curr = head;
16        ListNode* prev = NULL;
17        ListNode* next = head;
18        int n = 0;
19
20        int len = 0;
21
22        while(curr) {
23            len++;
24            curr = curr->next;
25            if(len == k) break;
26        }
27
28        curr = head;
29
30        if(len < k) return head;
31
32        while(n<k && curr) {
33            next = curr->next;
34            curr->next = prev;
35            prev = curr;
36            curr = next;
37            n++;
38        }
39
40        head->next = reverseKGroup(next, k);
41
42        return prev;
43    }
44};