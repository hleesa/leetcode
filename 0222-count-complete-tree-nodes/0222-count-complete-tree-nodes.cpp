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
    int getNodes(int n){
        int num = 2;
        for(int i = 1; i < n; ++i){
            num *= 2;
        }

        return num - 1;
    }

    int countNodes(TreeNode* root) {
        if(root == nullptr) return 0;

        int lh = 1;
        TreeNode* lc = root->left;
        while(lc != nullptr){
            ++lh;
            lc = lc->left;
        }

        int rh = 1;
        TreeNode* rc = root->right;
        while(rc != nullptr){
            ++rh;
            rc = rc->right;
        }

        if(lh == rh){
            return getNodes(lh);
        }
        else{
            return countNodes(root->left) + countNodes(root->right) + 1;
        }
    }
};