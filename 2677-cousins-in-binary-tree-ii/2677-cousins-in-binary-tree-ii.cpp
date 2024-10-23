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
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode*> q;
        queue<int> levelSums;
        q.push(root);

        while(!q.empty()){            
            int levelSize = q.size();
            int levelSum = 0;
            for(int i = 0; i < levelSize; ++i){
                TreeNode* cur = q.front();
                q.pop();
                levelSum += cur->val;
                if(cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            levelSums.push(levelSum);
        }

        q.push(root);
        levelSums.pop();
        root->val = 0;
        while(!q.empty()){
            int levelSize = q.size();
            for(int i = 0; i < levelSize; ++i){
                TreeNode* cur = q.front();
                q.pop();

                int siblingSum = (cur->left ? cur->left->val : 0) + (cur->right ? cur->right->val : 0);
                if (cur->left){
                    cur->left->val = levelSums.front() - siblingSum;
                    q.push(cur->left);
                }
                if(cur->right){
                    cur->right->val = levelSums.front() - siblingSum;
                    q.push(cur->right);
                }
            }
            levelSums.pop();
        }
        return root;
    }
};