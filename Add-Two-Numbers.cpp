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
13    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
14        ListNode* ans = new ListNode(-1);
15        ListNode* res = ans;
16        int carry = 0;
17
18        while(l1 || l2 || carry) {
19            int val = 0;
20            if(l1 && l2) {
21                val = l1->val + l2->val + carry;
22                carry = 0;
23                l1 = l1->next;
24                l2 = l2->next;
25            } else if(l1) {
26                val = l1->val + carry;
27                carry = 0;
28                l1 = l1->next;
29            } else if(l2) {
30                val = l2->val + carry;
31                carry = 0;
32                l2 = l2->next;
33            } else {
34                val = carry;
35                carry = 0;
36            }
37
38            if(val > 9) {
39                    carry = val/10;
40                    val = val%10;
41            }
42
43            ans->next = new ListNode(val);
44            ans = ans->next;
45        }
46
47        return res->next;
48    }
49};