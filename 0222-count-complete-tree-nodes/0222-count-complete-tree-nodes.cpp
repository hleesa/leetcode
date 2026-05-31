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
    int getH(TreeNode* root, bool left){
        int h = 0;
        while(root != nullptr){
            ++h;
            if(left){
                root = root->left;
            }
            else{
                root = root->right;
            }
        }
        
        return h;
    }
    int countNodes(TreeNode* root) {
        if(root == nullptr) return 0;

        int lh = getH(root, true);
        int rh = getH(root, false);

        if(lh == rh){
            return (1 << lh) - 1;
        }
        else{
            return countNodes(root->left) + countNodes(root->right) + 1;
        }
    }
};