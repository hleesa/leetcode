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
class FindElements {
public:
    FindElements(TreeNode* root) {
        root->val = 0;
        findElement(root);
    }

    void findElement(TreeNode* root){
        if(root->left != nullptr){
            root->left->val = root->val * 2 + 1;
            tree.insert(root->left->val);
            findElement(root->left);
        }
        if(root->right != nullptr){
            root->right->val = root->val * 2 + 2;
            tree.insert(root->right->val);
            findElement(root->right);
        }
    }
    
    bool find(int target) {
        return target == 0 || tree.contains(target);
    }

private:
    set<int> tree;
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */