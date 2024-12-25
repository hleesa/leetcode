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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        search(root, ans, 0);
        return ans;
    }
private:
    void search(TreeNode* root, vector<int>& ans, int row){
        if(root == nullptr){
            return;
        }
        if (ans.size() == row){
            ans.push_back(root->val);
        }
        else{
            ans[row] = max(root->val, ans[row]);
        }
        search(root->left, ans, row + 1);
        search(root->right, ans, row + 1);
    }
};