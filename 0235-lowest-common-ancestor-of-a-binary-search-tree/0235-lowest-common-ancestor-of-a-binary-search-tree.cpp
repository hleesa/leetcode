/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(q->val < p->val ){
            swap(p,q);
        }
        if(root == nullptr || (p->val <= root->val && root->val <= q->val)){
            return root;
        }
        else if (q->val <= root->val){
            return lowestCommonAncestor(root->left, p, q);
        }
        else if (root->val <= p->val){
            return lowestCommonAncestor(root->right, p, q);
        }
        return nullptr;
    }
};