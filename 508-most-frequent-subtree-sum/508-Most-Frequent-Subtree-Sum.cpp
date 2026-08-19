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

    int solve(TreeNode* root, unordered_map<int, int>& mp) {
        if(!root) return 0;

        int l = solve(root->left, mp);
        int r = solve(root->right, mp);

        mp[root->val + l + r]++;

        return root->val + l + r;
    }

    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> mp;
        vector<int> ans;

        int val = solve(root, mp);
        int x = 0;
        // mp[val]++;
        
        for(auto& [val, freq] : mp) {
            x = max(x, freq);
        }

        for(auto& [val, freq] : mp) {
            if(freq == x) ans.push_back(val);
        }

        return ans;
    }
};