/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    int depth(Node* root) {
        if (!root)
            return 0;

        int l = depth(root->left) + 1;
        int r = depth(root->right) + 1;

        return max(l, r);
    }

    void solve(Node* root, vector<Node*>& mp, int i) {
        if (!root)
            return;

        if (mp[i] != NULL)
            root->next = mp[i];
            

        
        solve(root->right, mp, i + 1);


        solve(root->left, mp, i + 1);
        mp[i] = root;
    }

    Node* connect(Node* root) {
        if (!root)
            return root;
        int d = depth(root);

        vector<Node*> mp(d, NULL);

        solve(root, mp, 0);

        return root;
    }
};