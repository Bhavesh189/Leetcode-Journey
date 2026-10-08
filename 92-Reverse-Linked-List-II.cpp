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

        ListNode* curr = head;

        int count = 1;
        ListNode* prev = NULL;

        while (count != left) {
            count++;
            prev = curr;
            curr = curr->next;
        }

        ListNode* st = curr;
        ListNode* pst = prev;
        prev = NULL;
        ListNode* n = curr->next;

        while (count != right+1) {
            count++;
            n = curr->next;
            curr->next = prev;
            prev = curr;
            curr = n;
        }

        st->next = n;
        if(pst) pst->next = prev;
        else return prev;

        return head;
    }
};