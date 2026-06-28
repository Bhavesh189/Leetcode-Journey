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
13    ListNode* merge(ListNode* one, ListNode* two) {
14        if(!one && !two) return NULL;
15        if(!one) return two;
16        if(!two) return one;
17
18        ListNode *a = new ListNode(-1), *ans = a;
19
20        while(one || two) {
21            ListNode* node = new ListNode(-1);
22            if(one && two) {
23                if(one->val < two->val) {
24                    node->val = one->val;
25                    one = one->next;
26                } else {
27                    node->val = two->val;
28                    two = two->next;
29                }
30
31                a->next = node;
32                a = a->next;
33            } else if(one) {
34                node->val = one->val;
35                one = one->next;
36                a->next = node;
37                a = a->next;
38            } else {
39                node->val = two->val;
40                two = two->next;
41                a->next = node;
42                a = a->next;
43            }
44        }
45
46        return ans->next;
47    }
48    ListNode* sortList(ListNode* head) {
49        if(!head) return NULL;
50        if(!head->next) return head;
51
52        ListNode* prev = NULL;
53        ListNode* slow = head;
54        ListNode* fast = head;
55
56        while(fast && fast->next) {
57            prev = slow;
58            slow = slow->next;
59            fast = fast->next->next;
60        }
61
62        prev->next = NULL;
63        head = sortList(head);
64        slow = sortList(slow);
65
66
67
68        return merge(head, slow);
69
70    }
71};