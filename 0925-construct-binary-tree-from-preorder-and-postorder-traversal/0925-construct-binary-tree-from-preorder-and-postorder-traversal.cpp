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
    unordered_map<int, int> postIndexMap;
    int preIndex =0;

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        for(int i = 0; i < postorder.size(); ++i){
            postIndexMap[postorder[i]] = i;
        }
        return buildTree(preorder, postorder, 0, postorder.size() - 1);
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& postorder, int left, int right){
        if (left > right) return nullptr;

        TreeNode* root = new TreeNode(preorder[preIndex++]);
        if(left == right) return root;

        int postLeftRootIndex = postIndexMap[preorder[preIndex]];
        root->left = buildTree(preorder, postorder, left, postLeftRootIndex);
        root->right = buildTree(preorder, postorder, postLeftRootIndex + 1, right - 1);

        return root;
    }

};