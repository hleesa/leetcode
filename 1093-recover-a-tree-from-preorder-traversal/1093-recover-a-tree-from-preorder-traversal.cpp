class Solution {
public:
    TreeNode* recoverFromPreorder(string traversal) {
        stack<pair<TreeNode*, int>> stk;
        int i = 0;
        while (i < traversal.size()) {
            int depth = 0;
            
            while (i < traversal.size() && traversal[i] == '-') {
                depth++;
                i++;
            }
            
            int num = 0;
            while (i < traversal.size() && isdigit(traversal[i])) {
                num = num * 10 + (traversal[i] - '0');
                i++;
            }
            
            TreeNode* node = new TreeNode(num);
            while (!stk.empty() && stk.top().second >= depth) {
                stk.pop();
            }
            
            if (!stk.empty()) {
                TreeNode* parent = stk.top().first;
                if (!parent->left) {
                    parent->left = node;
                } else {
                    parent->right = node;
                }
            }
            
            stk.push({node, depth});
        }
        
        while (stk.size() > 1) {
            stk.pop();
        }
        
        return stk.top().first;
    }
};
