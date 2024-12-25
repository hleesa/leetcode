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
        map<int, int> levelToMaxValue;
        search(root, levelToMaxValue, 0);
        vector<int> ans;
        for(const auto& it : levelToMaxValue){
            ans.push_back(it.second);
        }
        return ans;
    }
private:
    void search(TreeNode* root, map<int, int>& levelToMaxValue, int row){
        if(root == nullptr){
            return;
        }
        if (levelToMaxValue.find(row) == levelToMaxValue.end() || root->val > levelToMaxValue[row]){
            levelToMaxValue[row] = root->val;
        }
        search(root->left, levelToMaxValue, row + 1);
        search(root->right, levelToMaxValue, row + 1);
    }
};