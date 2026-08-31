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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> nums;

        while (head) {
            nums.push_back(head->val);
            head = head->next;
        }

        vector<int> idx;

        for (int i = 1; i < nums.size() - 1; i++) {
            if (((nums[i - 1] < nums[i]) && (nums[i + 1] < nums[i])) ||
                ((nums[i - 1] > nums[i]) && (nums[i + 1] > nums[i]))) idx.push_back(i);
        }

        if(idx.size() <= 1) return {-1, -1};

        int mi = INT_MAX;

        for(int i = 0; i < idx.size()-1; i++) {
            mi = min(mi, abs(idx[i]-idx[i+1]));
        }

        int mx = -1;

        mx = abs(idx[idx.size()-1]-idx[0]);

        return {mi, mx};
    }
};