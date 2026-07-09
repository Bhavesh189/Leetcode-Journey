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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || !head->next || left == right)
            return head;

        ListNode *curr = head, *prev = NULL;

        for (int i = 1; i < left; i++) {
            prev = curr;
            curr = curr->next;
        }

        ListNode *p = nullptr, *x = curr;
        right = right - left + 1;

        while (curr && right) {
            ListNode* n = curr->next;
            curr->next = p;
            p = curr;
            curr = n;
            right--;
        }

        if (prev)
            prev->next = p;
        else
            head = p;
        if (x)
            x->next = curr;

        return head;
    }
};