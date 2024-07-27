/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool isMatch(TreeNode* s, TreeNode* t) {
        if (!s and !t)
            return true;
        if (!s or !t)
            return false;
        return s->val == t->val and isMatch(s->left, t->left) and
               isMatch(s->right, t->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root)
            return false;
        return isMatch(root, subRoot) or isSubtree(root->left, subRoot) or
               isSubtree(root->right, subRoot);
    }
};
