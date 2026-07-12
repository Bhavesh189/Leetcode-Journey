/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *curr = head, *prev = NULL, *ans = new ListNode(-1), *c = ans;

        while (curr) {
            if (curr->val >= x) {
                ListNode* next = curr->next;
                c->next = curr;
                c = c->next;
                c->next = NULL;
                if (prev) {
                    prev->next = next;
                } else
                    head = next;
                curr = next;
                continue;
            }
            prev = curr;
            curr = curr->next;
        }

        curr = head;

        while (curr && curr->next) {
            curr = curr->next;
        }

        if (curr)
            curr->next = ans->next;
        else return ans->next;

        return head;
    }
};