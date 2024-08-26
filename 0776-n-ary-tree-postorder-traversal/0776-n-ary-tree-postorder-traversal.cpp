/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        if(root == nullptr){
            return vector<int>();
        }
        vector<int> ret;
        for(const auto& child : root->children){
            vector<int> children = postorder(child);
            ret.insert(ret.end(), children.begin(), children.end());
        }
        ret.push_back(root->val);
        return ret;
    }
};