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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        map<int, long long> levelToSum;
        traverse(root, levelToSum, 1);
        vector<long long> sums;
        for(auto it : levelToSum){
            sums.push_back(it.second);
        }
        if (k > sums.size()){
            return -1;
        }
        sort(sums.begin(), sums.end());
        return sums[sums.size() - k];
    }
private:
    void traverse(TreeNode* root, map<int, long long>& levelToSum, int level){
        if(root == nullptr){
            return;
        }
        levelToSum[level] += root->val;
        traverse(root->left, levelToSum, level+1);
        traverse(root->right, levelToSum, level+1);
    }
};