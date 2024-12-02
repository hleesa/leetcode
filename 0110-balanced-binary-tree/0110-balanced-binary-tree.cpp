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
    bool isBalanced(TreeNode* root) {
        return height(root, 0) != -1;
    }

private:
    int height(TreeNode* root, int dep){
        if(root == nullptr) return dep;

        int leftHeight = height(root->left, dep + 1);
        int rightHeight = height(root->right, dep + 1);
        if(leftHeight == 0 || rightHeight == 0) return 0;
        if(abs(leftHeight - rightHeight) > 1) return -1;

        return max(leftHeight, rightHeight);
    }
};