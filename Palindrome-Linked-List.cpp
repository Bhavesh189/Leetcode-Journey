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
13
14    ListNode* reverse(ListNode* head) {
15        if(!head) return NULL;
16
17        ListNode* prev = NULL;
18        ListNode* next = NULL;
19
20        while(head) {
21            next = head->next;
22            head->next = prev;
23            prev = head;
24            head = next;
25        }
26
27        return prev;
28    }
29
30    bool isPalindrome(ListNode* head) {
31
32        ListNode *fast = head, *slow = head;
33
34        while(fast && fast->next) {
35            fast = fast->next->next;
36            slow = slow->next;
37        }
38
39        ListNode* rev = reverse(slow);
40
41        while(rev) {
42            if(head->val != rev->val) return false;
43            head = head->next;
44            rev = rev->next;
45        }
46
47        return true;
48    }
49};