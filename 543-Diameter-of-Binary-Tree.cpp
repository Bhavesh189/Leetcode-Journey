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

    int solve(TreeNode* root, pair<int, int> &p) {
        if(!root) return 0;

        int l = 1 + solve(root->left, p);
        int r = 1 + solve(root->right, p);

        pair<int, int> t = {l, r};
        if(l+r-2 > p.first+p.second-2) p = t;

        return max(l, r);
    }


    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int ans = 0;
        pair<int, int> p;
        solve(root, p);

        return p.first+p.second-2;
    }
};