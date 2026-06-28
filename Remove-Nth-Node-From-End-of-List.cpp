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
13    ListNode* removeNthFromEnd(ListNode* head, int n) {
14        if(!head) return head;
15        ListNode* curr = head;
16        int len = 0;
17
18        while(curr) {
19            len++;
20            curr = curr->next;
21        }
22
23        if(len == n) {
24            if(len == 1) return NULL;
25            else return head->next;
26        }
27
28        curr = head;
29        int x = len-n;
30        int c = 1;
31
32        while(c != x) {
33            curr = curr->next;
34            c++;
35        }
36
37        if(curr && curr->next)
38        curr->next = curr->next->next;
39
40        return head;
41    }
42};