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
    TreeNode* reverseOddLevels(TreeNode* root) {
        reverseOddLevel(root->left, root->right, 0);
        return root; 
    }
    void reverseOddLevel(TreeNode* left, TreeNode* right, int level){
        if(left == nullptr || right == nullptr){
            return;
        }
        if (level % 2 == 0){
            swap(left->val, right->val);
        }
        reverseOddLevel(left->left, right->right, level + 1);
        reverseOddLevel(left->right, right->left, level + 1);
    }
};