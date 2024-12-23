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
    int minimumOperations(TreeNode* root) {
        map<int,vector<int>> levelToLeaves;
        getNodeValue(root, levelToLeaves, 0);
        int operations = 0;
        for(auto& it : levelToLeaves){
            vector<int> sorted = it.second;
            sort(sorted.begin(), sorted.end());
            const int n = sorted.size();
            for(int i = 0; i < n; ++i){
                if (it.second[i] != sorted[i]){
                    int j = i + 1;
                    while(it.second[j] != sorted[i]) ++j;
                    swap(it.second[j], it.second[i]);
                    ++operations;
                }
            }
        }
        return operations;
    }
private:
    void getNodeValue(TreeNode* root, map<int, vector<int>>& levelToLeaves, int level){
        if(root == nullptr){
            return;
        }
        levelToLeaves[level].push_back(root->val);
        getNodeValue(root->left, levelToLeaves, level + 1);
        getNodeValue(root->right, levelToLeaves, level + 1);
        return ;
    }
};
