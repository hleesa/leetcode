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
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        unordered_map<int, int> nodeDepth, heightAtNode;
        vector<int> levelMaxHeight;
        
        int treeHeight = dfs(root, nodeDepth, heightAtNode, 0);

        vector<pair<int, int>> levelHeight(treeHeight + 1, {0, 0});
        for (auto& [node, height] : heightAtNode) {
            int depth = nodeDepth[node];
            if (height >= levelHeight[depth].first) {
                levelHeight[depth].second = levelHeight[depth].first;
                levelHeight[depth].first = height;
            } else if (height > levelHeight[depth].second) {
                levelHeight[depth].second = height;
            }
        }
        
        vector<int> result;
        for (int query : queries) {
            int depth = nodeDepth[query];
            int height = heightAtNode[query];
            
            int maxHeightAfterRemoval;

            if (height == levelHeight[depth].first) {
                maxHeightAfterRemoval = treeHeight - height + levelHeight[depth].second;
            } else {
                maxHeightAfterRemoval = treeHeight;
            }
            result.push_back(maxHeightAfterRemoval - 1);
        }
        
        return result;
    }

private:
    int dfs(TreeNode* node, unordered_map<int, int>& nodeDepth, unordered_map<int, int>& heightAtNode, int depth) {
        if (!node) return 0;
        
        nodeDepth[node->val] = depth;
        
        int leftHeight = dfs(node->left, nodeDepth, heightAtNode, depth + 1);
        int rightHeight = dfs(node->right, nodeDepth, heightAtNode, depth + 1);
        
        int nodeHeight = max(leftHeight, rightHeight) + 1;
        heightAtNode[node->val] = nodeHeight;
        
        return nodeHeight;
    }
};