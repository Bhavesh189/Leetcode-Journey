1/**
2 * Definition for singly-linked list.
3 * struct ListNode {
4 *     int val;
5 *     ListNode *next;
6 *     ListNode(int x) : val(x), next(NULL) {}
7 * };
8 */
9class Solution {
10public:
11    ListNode *detectCycle(ListNode *head) {
12        ListNode* fast = head;
13        ListNode* slow = head;
14
15        while(fast && fast->next) {
16            fast = fast->next->next;
17            slow = slow->next;
18
19            if(fast == slow) {
20                fast = head;
21                while(fast != slow) {
22                    fast = fast->next;
23                    slow = slow->next;
24                }
25
26                return fast;
27            }
28        }
29
30        return NULL;
31    }
32};