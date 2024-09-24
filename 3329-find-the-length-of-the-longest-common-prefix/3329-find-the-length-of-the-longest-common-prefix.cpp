class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie trie;
    
        for (int num : arr1) {
            trie.insert(num);
        }
        int maxLength = 0;
        
        for (int num : arr2) {
            int len = trie.findLongestCommonPrefix(num);
            maxLength = max(maxLength, len);
        }
        return maxLength;
    }

    struct TrieNode {
        TrieNode* children[10];  // 0부터 9까지 숫자 자리를 저장할 수 있음
        TrieNode() {
            for (int i = 0; i < 10; i++) {
                children[i] = nullptr;
            }
        }
    };

    class Trie {
    public:
        TrieNode* root;
        
        Trie() {
            root = new TrieNode();
        }
        
        void insert(int num) {
            string s = to_string(num);
            TrieNode* node = root;
            for (char c : s) {
                int idx = c - '0';
                if (node->children[idx] == nullptr) {
                    node->children[idx] = new TrieNode();
                }
                node = node->children[idx];
            }
        }
        
        int findLongestCommonPrefix(int num) {
            string s = to_string(num);
            TrieNode* node = root;
            int length = 0;
            
            for (char c : s) {
                int idx = c - '0';
                if (node->children[idx] == nullptr) {
                    break; 
                }
                node = node->children[idx];
                length++;
            }
            
            return length;
        }
    };
};