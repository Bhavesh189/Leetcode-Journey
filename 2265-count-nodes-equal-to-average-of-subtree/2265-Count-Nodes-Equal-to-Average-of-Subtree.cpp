/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    pair<int, int> solve(TreeNode* root, int n, int sum, int& ans) {
        if(!root) return {0, 0};

        auto left = solve(root->left, 0, 0, ans);
        auto right = solve(root->right, 0, 0, ans);

        int lc = left.first, rc = right.first;
        int ls = left.second, rs = right.second;

        if(lc+rc+1 != 0 && ((root->val+rs+ls)/ (lc+rc+1)) == root->val) ans++;

        return {lc+rc+1, ls+rs+root->val};
    }

    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        solve(root, 0, 0, ans);

        return ans;
    }
};